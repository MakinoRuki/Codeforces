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
#define M 10000002
#define N 1002
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans = 0LL;
    for (int i = 1; i < n; ++i) {
      ans = max(ans, (ll)a[i] + (ll)a[i+1]);
    }
    for (int i = 1; i < n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        if (i - 1 >= 1) {
          ans = max(ans, (ll)a[j]+(ll)a[i-1]);
        }
        if (j+1 <= n) {
          ans = max(ans, (ll)a[i] + (ll)a[j+1]);
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
