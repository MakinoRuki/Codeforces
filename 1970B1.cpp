/*
因为a[i]都是偶数，所以可以都放在对角线上。根据a[i]的大小排序，大的往两个角放，小的往中间放。
*/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
int b[N];
int c[N];
int d[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>n;
  vector<pair<int,int>> rk;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    rk.push_back(make_pair(a[i], i));
  }
  sort(rk.begin(), rk.end());
  reverse(rk.begin(), rk.end());
  int l = 1, r = n;
  for (int i = 0; i < rk.size(); i += 2) {
    int id = rk[i].second;
    b[id] = l, c[l] = id;
    l++;
    if (i +1 < rk.size()) {
      id = rk[i+1].second;
      b[id] = r, c[r] = id;
      r--;
    }
  }
  bool ok=true;
  for (int i = 1; i <= n; ++i) {
    int x=b[i];
    int y=b[i];
    int dt = a[i]/2;
    if (x-dt>=1) {
      d[i] = c[x-dt];
    } else if (x + dt <= n) {
      d[i] = c[x+dt];
    } else {
      ok=false;
      break;
    }
  }
  if (!ok) puts("NO");
  else {
    puts("YES");
    for (int i =1 ; i <= n; ++i) {
      printf("%d %d\n", b[i], b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", d[i]);
    }
    cout<<endl;
  }
  return 0;
}

