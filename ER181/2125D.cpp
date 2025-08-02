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
#define N 200005
#define M 1002
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
int b[N];
vector<pair<int, ll>> sg[N];
ll dp[N];
ll getpw(ll x, ll y) {
    ll res=1LL;
    while(y) {
        if (y&1) res=res*x%mod2;
        x=x*x%mod2;
        y /= 2;
    }
    return res;
}
int main() {
//   cin>>t;
//   for (int cas=1; cas<=t; ++cas) {
//     scanf("%d", &n);
    
//   }
  cin>>n>>m;
  for (int i = 0; i <= m; ++i) {
      sg[i].clear();
  }
  ll tmp = 1LL;
  for (int i = 1; i <= n; ++i) {
      int l,r;
      ll p,q;
      scanf("%d%d%lld%lld", &l, &r, &p, &q);
      ll p1 = p * getpw(q, mod2-2) % mod2;
      ll p2 = (q-p) % mod2 * getpw(q, mod2-2) % mod2;
      sg[l].push_back(make_pair(r, p1 * getpw(p2, mod2-2) % mod2));
      tmp = tmp * p2 % mod2;
  }
  dp[0] = tmp;
  for (int i = 0; i < m; ++i) {
      for (auto pr : sg[i+1]) {
          int r = pr.first;
          ll p = pr.second;
          dp[r] = (dp[r] + dp[i] * p % mod2) % mod2;
      }
  }
  printf("%lld\n", dp[m]);

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
