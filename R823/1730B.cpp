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
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int b[N];
//int l[N], r[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      rk.push_back(make_pair(a[i], b[i]));
    }
    sort(rk.begin(), rk.end());
    double l = 0.0, r = 300000000.0;
    double ans = 0.0;
    for (int j = 1; j <= 250; ++j) {
    //  if (j <= 100) cout<<"lr="<<l<<" "<<r<<endl;
      double res = (l+r)*0.5;
      bool ok=true;
      double bg = 0.0, ed = 0.0;
      for (int i = 0; i < n; ++i) {
        if (res < rk[i].second) {
          ok=false;
          break;
        }
        double dt = res-rk[i].second;
        double l1 = rk[i].first-dt;
        double r1 = rk[i].first+dt;
        if (i == 0) {
          bg = rk[i].first-dt;
          ed = rk[i].first+dt;
        } else {
          if (l1 > ed || r1 < bg) {
            ok=false;
            break;
          }
          bg = max(bg, l1);
          ed = min(ed, r1);
        }
       // if (res==1) cout<<"xy="<<bg<<" "<<ed<<endl;
      }
      if (ok) {
        ans = bg;
        r = res;
      } else {
        l = res;
      }
    }
    // vector<pair<int,int>> rk2;
    // rk2.clear();
    // for (int i = 0; i < rk.size(); ++i) {
    //   if (rk2.empty() || rk2.back().first != rk[i].first) {
    //     rk2.push_back(rk[i]);
    //   } else {
    //     rk2.back().second = max(rk2.back().second, rk[i].second);
    //   }
    // }
    // n = (int)rk2.size();
    // rk.clear();
    // for (int i = 0; i < n; ++i) {
    //   rk.push_back(rk2[i]);
    // }
    // for (int i = 1; i <= n; ++i) {
    //   if (i == 1) {
    //     l[i] = rk[i-1].second;
    //   } else {
    //     int dt = rk[i-1].first-rk[i-2].first;
    //     l[i] = max(l[i-1] + dt, rk[i-1].second);
    //   }
    // }
    // for (int i = n; i >= 1; --i) {
    //   if (i == n) {
    //     r[i] = rk[i-1].second;
    //   } else {
    //     int dt = rk[i].first - rk[i-1].first;
    //     r[i] = max(r[i+1] + dt, rk[i-1].second);
    //   }
    // }
    // // double ll = 0.0;
    // // double rr = 300000000.0;
    // // double ans = 0.0;
    // // for (int i = 1; i <= 500; ++i) {
    // //   if (i <= 100) cout<<"i="<<i<<" "<<ll<<" "<<rr<<endl;
    // //   double res = (ll+rr)*0.5;
    // //   bool found=false;
    // //   for (int j = 1; j <= n; ++j) {
    // //     if (j < n) {
    // //       int dt = rk[j].first - rk[j-1].first;
    // //       if (res>=l[j] && res<=l[j]+dt && res>=r[j+1] && res <= r[j+1]+dt) {
    // //         found=true;
    // //         ans = res-l[j]+rk[j-1].first;
    // //         break;
    // //       }
    // //     } else {
    // //       if (res >= l[j]) {
    // //         found=true;
    // //         ans = rk.back().first;
    // //       }
    // //     }
    // //   }
    // //   if (found) {
    // //     rr = res;
    // //   } else {
    // //     ll = res;
    // //   }
    // // }
    // ll res = -1;
    // double ans = 0.0;
    // for (int i = 1; i <= n; ++i) {
    //   if (i < n) {
    //     ll dt = rk[i].first - rk[i-1].first;
    //     ll tmp = (l[i] + r[i+1] + dt);
    //     if (tmp >= 2*l[i] && tmp <= 2*(dt+l[i]) && tmp >= 2*r[i+1] && tmp <= 2*(dt+r[i+1]) && (res <0 || tmp < res)) {
    //       res = tmp;
    //       ans = tmp*0.5-l[i] + rk[i-1].first;
    //     }
    //   }
    // }
    // if (res < 0 || l[n]*2<res) {
    //   ans = rk.back().first;
    // }
    printf("%.10lf\n", ans);
  }
  return 0;
}
