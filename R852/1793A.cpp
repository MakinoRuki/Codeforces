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
#define N 1000005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll a,b;
    ll n, m;
    scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
    ll x = n/(m+1);
    ll y = n%(m+1);
    ll ans = 0LL;
    if (x >= 1) {
      if (m* a <= (m+1)*b) {
        ans += x * m * a;
      } else {
        ans += x * (m+1) * b;
      }
    }
    if (a >= b) ans += y * b;
    else ans += y * a;
    printf("%lld\n", ans);
  }
  return 0;
}
