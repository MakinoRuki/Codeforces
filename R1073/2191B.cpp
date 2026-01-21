
#include <iostream>
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
#define N 1000005
#define M 1500
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int c[N];
bool check(int c1, int c2) {
  vector<pair<int,int>> rk;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    if (i&1) c[i]=c1;
    else c[i] = !c1;
    rk.push_back(make_pair(a[i], i));
  }
  sort(rk.begin(), rk.end());
  for (int i = 1; i <= n; ++i) {
    int id = rk[i-1].second;
    int cc = (i&1) ? c2 : !c2;
    if (cc != c[id]) return false;
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int c0=0,c1=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i]==0) c0++;
      else if (a[i] == 1) c1++;
    }
    if (!c0) {
      puts("No");
    } else {
      if (!c1) {
        if (c0 > 1) puts("No");
        else puts("Yes");
      } else {
        puts("Yes");
      }
    }
  }
  
  return 0;
}

