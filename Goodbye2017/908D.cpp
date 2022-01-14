#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<double> ans;
ll dp[N][N];
int pa,pb;
ll getpw(ll x, ll y) {
  ll res= 1LL;
  while(y) {
    if (y&1) res = res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
ll dfs(int a, int b) {
  if (dp[a][b] >= 0) {
    return dp[a][b];
  }
//  cout<<a<<" "<<b<<endl;
  if (a + b >= k) {
    ll tmp = pa % mod * getpw(pb, mod-2) % mod;
    return dp[a][b] = (a+b+tmp)%mod;
  }
  ll p1 = pa % mod * getpw(pa+pb, mod-2) % mod;
  ll p2 = pb % mod * getpw(pa+pb, mod-2) % mod;
  return dp[a][b] = (p1 * dfs(a+1, b) % mod + p2 * dfs(a,b+a) % mod) % mod;
}
int main() {
  cin>>k>>pa>>pb;
  memset(dp, -1, sizeof(dp));
  ll res = dfs(1, 0);
  cout<<res<<endl;
//  cout<<341LL*getpw(100LL,mod-2)%mod<<endl;
  return 0;
}
