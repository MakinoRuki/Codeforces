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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
ll f[2][M][M];
ll g[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      g[i] = 0LL;
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j <= k; ++j) {
        for (int j2 = 0; j2 <= k; ++j2) {
          f[i][j][j2] = -(1LL<<61);
        }
      }
    }
    f[0][0][0] = 0LL;
    for (int i = 0; i < n; ++i) {
      int now = i&1;
      for (int j = 0; j <= k; ++j) {
        for (int j2 = 0; j2 <= k; ++j2) {
          f[now^1][j][j2] = -(1LL<<61);
        }
      }
      g[i+1] = max(g[i+1], g[i]);
      for (int j = 0; j <= k; ++j) {
        for (int j2 = 0; j2 <= k; ++j2) {
          if (f[now][j][j2] > -(1LL<<61)) {
            f[now^1][j][j2] = max(f[now^1][j][j2], f[now][j][j2] + (ll)a[i+1] - (ll)x);
            if (n-i-1+j >= k) g[i+1] = max(g[i+1], f[now^1][j][j2]);
           // if (g[i+1] == 56) cout<<"ij1="<<i<<" "<<j<<endl;
            if (j+1<=k) {
              f[now^1][j+1][j2+1] = max(f[now^1][j+1][j2+1], f[now][j][j2] + (ll)a[i+1] + (ll)x);
              if (n-i+j >= k) g[i+1] = max(g[i+1], f[now^1][j+1][j2+1]);
             // if (g[i+1] == 56) cout<<"ij2="<<i<<" "<<j<<endl;
            }
            f[now^1][j][0] = max(f[now^1][j][0], (ll)a[i+1] - (ll)x);
            if (n-i-1+j >= k) g[i+1] = max(g[i+1], f[now^1][j][0]);
           // if (g[i+1] == 56) cout<<"ij3="<<i<<" "<<j<<endl;
            if (j+1 <= k) {
              f[now^1][j+1][1] = max(f[now^1][j+1][1], (ll)a[i+1] + (ll)x);
              if (n-i+j>=k) g[i+1] = max(g[i+1], f[now^1][j+1][1]);
              //if (g[i+1] == 56) cout<<"ij4="<<i<<" "<<j<<endl;
            }
          }
        }
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 0; j <= k; ++j) {
    //     cout<<"ij="<<i<<" "<<j<<" "<<f[i][j]<<endl;
    //   }
    // }
    ll ans = 0LL;
    for (int i = 0; i <= n; ++i) {
      ans = max(ans, g[i]);
    }
    printf("%lld\n", ans);
    // if (x >= 0) {
    //   printf("%lld\n", ans);
    // } else {
    //   ll sum = 0LL;
    //   ll mx = 0LL;
    //   int len=0;
    //   int cnt = n+1;
    //   for (int i = 1; i <= n; ++i) {
    //     sum += a[i];
    //     len++;
    //     if (sum < 0) {
    //       sum = 0;
    //       len = 0;
    //     }
    //     if (sum > mx) {
    //       mx = sum;
    //       cnt = len;
    //     } else if (sum == mx && len < cnt) {
    //       cnt = len;
    //     }
    //   }
    //   if (n - cnt >= k) {
    //     printf("%lld\n", mx);
    //   } else {
    //     ll dt = (k-(n-cnt));
    //     if (mx + dt * x > 0) {
    //       printf("%lld\n", mx + dt * x);
    //     } else {
    //       puts("0");
    //     }
    //   }
    // }
  }
  return 0;
}
