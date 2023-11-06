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
#define N 300005
#define M 510
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
    int g;
    scanf("%d%d%d", &n, &k, &g);
    ll tot=(ll)k*(ll)g;
    ll ans=0LL;
    if (g % 2) {
      ll dt = min(tot, (ll)(n-1)*(ll)(g/2));
      ans += dt;
      tot -= dt;
      tot %= g;
      if (tot >= (g+1)/2) {
        ans -= g-tot;
      } else {
        ans += tot;
      }
    } else {
      ll dt = min(tot, (ll)(n-1)*(ll)(g/2-1));
      ans += dt;
      tot -= dt;
      tot %= g;
      if (tot >= g/2) {
        ans -= g-tot;
      } else {
        ans += tot;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
