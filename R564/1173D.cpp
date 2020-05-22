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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
int deg[N];
ll fac[N];
int main() {
  cin>>n;
  ll ans=1LL;
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++;
    deg[v]++;
  }
  fac[0] = 1LL;
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i-1]*(ll)i % mod;
  }
  for (int i = 1; i <= n; ++i) {
    ans = ans*fac[deg[i]]%mod;
  }
  ans = ans*(ll)n % mod;
  cout<<ans<<endl;
  return 0;
}
