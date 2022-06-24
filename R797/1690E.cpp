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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int cnt[M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= k; ++i) {
      cnt[i] = 0;
    }
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += a[i]/k;
      cnt[a[i]%k]++;
    }
    ll sum=0LL;
    int l = 1, r = k-1;
    while(l <= r) {
      if (l < r) {
        if (l+r<k) {
          l++;
        } else {
          int dt = min(cnt[l], cnt[r]);
          cnt[l] -= dt;
          cnt[r] -= dt;
          tot += dt;
          if (cnt[l] <= 0) l++;
          if (cnt[r] <= 0) r--;
        }
      } else {
        if (l+r>=k) {
          tot += cnt[l]/2;
        }
        break;
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
