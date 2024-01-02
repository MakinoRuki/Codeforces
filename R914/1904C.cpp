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
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<ll> v;
    v.clear();
    ll ans;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      v.push_back(a[i]);
      if (i == 1) ans = a[i];
      else ans = min(ans, a[i]);
    }
    if (k >= 3) {
      puts("0");
      continue;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
      ans = min(ans, (ll)(v[i]-v[i-1]));
    }
    if (k == 1) {
      printf("%lld\n", ans);
    } else {
      for (int i = 0; i < v.size(); ++i) {
        for (int j = i+1; j < v.size(); ++j) {
          ll dt = v[j]-v[i];
          ans = min(ans, dt);
          ans = min(ans, abs(v.back()-dt));
          ans = min(ans, abs(v[0]-dt));
          int id = upper_bound(v.begin(), v.end(), dt)-v.begin();
          if (id >= 0 && id < v.size()) {
            ans = min(ans, abs(dt-v[id]));
          }
          if (id-1 < v.size() && id-1>=0) {
            ans = min(ans, abs(dt-v[id-1]));
          }
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
