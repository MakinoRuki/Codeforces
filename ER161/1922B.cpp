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
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
      cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    // ll tot=0;
    // for (int i = 0; i <= n; ++i) {
    //   if (cnt[i]) tot++;
    // }
    ll ans = 0LL;
    ll sum=0LL;
    for (int i = 0; i <= n; ++i) {
      if (cnt[i] >= 3) {
        ll x=cnt[i];
        ans += x*(x-1)*(x-2)/6;
      }
      if (cnt[i] >= 2) {
        ll x=cnt[i];
        ans += (x*(x-1)/2)*sum;
      }
      sum += cnt[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
