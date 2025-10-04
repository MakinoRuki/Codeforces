
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
#define N 2000005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int sum[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      ss.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i]) ss.erase(a[i]);
    }
    vector<int> v(ss.begin(), ss.end());
    int cur=(int)v.size()-1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) {
        a[i] = v[cur];
        cur--;
      }
    }
    int l=-1,r=-1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != i) {
        if (l<0) l=i;
        else r=i;
      }
    }
    if (l>0) printf("%d\n", r-l+1);
    else puts("0");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
