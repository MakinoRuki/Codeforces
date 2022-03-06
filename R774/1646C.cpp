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
bool vis[50];
ll fac[17];
int main() {
  fac[0] = 1LL;
  for (int i = 1; i <= 15; ++i) {
    fac[i] = fac[i-1] * (ll)i;
  }
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    ll n;
    scanf("%lld", &n);
    int ans=-1;
    for (int i = 0; i < (1<<16); ++i) {
      ll m = n;
      // for (int j = 0; j <= 15; ++j) {
      //   vis[j] = false;
      // }
      bool has1 = false;
      bool has2 = false;
      int j;
      int cnt=0;
      for (j = 1; j <= 15; ++j) {
        if ((1<<j) & i) {
          if (m >= fac[j]) {
            m -= fac[j];
            if ((1<<j) == 1) has1=true;
            else if ((1<<j) == 2) has2 = true;
            cnt++;
          } else {
            break;
          }
        }
      }
      if (j <= 15) continue;
      int k;
      for (k = 40; k >= 0; --k) {
        if ((1LL<<k) <= m) {
          if (k >= 2 || ((k == 0) && !has1) || ((k == 1) && !has2)) {
            m -= (1LL<<k);
            cnt++;
          } else {
            break;
          }
        }
      }
      if (k < 0) {
        ans = (ans < 0 ? cnt : min(ans, cnt));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
