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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x;
    scanf("%d%lld", &n, &x);
    map<ll, int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      cnt[a[i]]++;
    }
    sort(a+1, a+n+1);
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      if (cnt[a[i]] > 0) {
        ll y = x * a[i];
        if (cnt[y] > 0) {
          cnt[y]--;
          cnt[a[i]]--;
        } else {
          ans++;
          cnt[a[i]]--;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
