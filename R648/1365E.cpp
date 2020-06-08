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
#define N 502
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
int t;
int n;
ll a[N];
bool vis[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  ll ans= a[1];
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i==j) continue;
      ans = max(ans, a[i]|a[j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (i == j || j == k || i == k) continue;
        ans = max(ans, a[i]|a[j]|a[k]);
      }
    }
  }
  cout<<ans<<endl;
  // if (n <= 2) {
  //   cout<<ans<<endl;
  // } else {
  //   int i;
  //   for (i = 60; i>=0; --i) {
  //     int j;
  //     for (j = 1; j <= n; ++j) {
  //       if ((1LL<<i)&a[j]) break;
  //     }
  //     if (j <= n) {
  //       break;
  //     }
  //   }
  //   memset(vis, false, sizeof(vis));
  //   vector<pair<ll,int>> rk;
  //   rk.clear();
  //   int tot=0;
  //   for (int j = 1; j <= n; ++j) {
  //     if ((1LL<<i) & a[j]) {
  //       vis[j] = true;
  //       tot++;
  //     } else {
  //       rk.push_back(make_pair(a[j], j));
  //     }
  //   }
  //   int num[62];
  //   memset(num, 0, sizeof(num));
  //   num[i] += tot;
  //   sort(rk.begin(), rk.end());
  //   reverse(rk.begin(), rk.end());
  //   for (int j = 0; j < min(2, (int)rk.size()); ++j) {
  //     vis[rk[j].second] = true;
  //     tot++;
  //   }
  //   ll res = 1LL<<i;
  //   for (int j = i-1; j >= 0; --j) {
  //     rk.clear();
  //     for (int k = 1; k <= n; ++k) {
  //       if (vis[k] && !((1LL<<j)&a[k])) {
  //         rk.push_back(make_pair(a[k], k));
  //       }
  //     }
  //     if (rk.size() <= 2) {
  //       num[j] += tot-rk.size();
  //       res |= (1LL<<j);
  //       continue;
  //     }
  //     int det = rk.size()-2;
  //     if (tot-det < 3) {
  //       continue;
  //     }
  //     sort(rk.begin(), rk.end());
  //     vector<pair<ll,int>> ids;
  //     ids.clear();
  //     for (int k = 0; k < rk.size(); ++k) {
  //       int x;
  //       for (x = 0; x <= 60; ++x) {
  //         if (((1LL<<x)&rk[k].first) && ((1LL<<x)&res)) {
  //           if (num[x] <= 1) {
  //             break;
  //           }
  //         }
  //       }
  //       if (x > 60) {
  //         ids.push_back(make_pair(a[k],k));
  //       }
  //     }
  //     if (ids.size() < det) {
  //       continue;
  //     }
  //     sort(ids.begin(), ids.end());
  //     for (int k = 0; k < det; ++k) {
  //       for (int x = 0; x <= 60; ++x) {
  //         if (((1LL<<x)&rk[k].first) && ((1LL<<x)&res)) {
  //           num[x]--;
  //         }
  //       }
  //       vis[ids[k].second] = false;
  //       tot--;
  //     }
  //     res |= (1LL<<j);
  //   }
  //   ans = max(ans, res);
  //   cout<<ans<<endl;
  // }
  return 0;
}
