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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i =1; i <= n+m; ++i) {
      cnt[i]=0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]] = m+1;
    }
    for (int i = 1; i <= m; ++i) {
      int p,v;
      scanf("%d%d", &p, &v);
      cnt[a[p]] -= m-i+1;
      a[p] = v;
      cnt[v] += m-i+1;
    }
    ll tot=0LL;
    for (int i =1; i <= n+m; ++i) {
      if (cnt[i]) {
        ll dt = (ll)cnt[i]*(ll)(cnt[i]-1)/2LL + (ll)cnt[i]*(ll)(m+1-cnt[i]);
        tot += dt;
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
