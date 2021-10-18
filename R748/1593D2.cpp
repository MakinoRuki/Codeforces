#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#define eps 1e-7
#define M 502
#define N 2000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
int a[N];
int cnt[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1;i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok=false;
    for (int i = 1; i <= n; ++i) {
      int cnt=0;
      for (int j = 1; j <= n; ++j) {
        if (a[j] == a[i]) {
          cnt++;
        }
      }
      if (cnt >= n/2) {
        ok=true;
        break;
      }
    }
    if (ok) {
      puts("-1");
    } else {
      int ans=0;
      // for (int i = 1; i <= 2000000; ++i) {
      //   int cnt=0;
      //   for (int j = 2; j * j <= i; ++j) {
      //     if (i%j == 0) {
      //       cnt++;
      //       if (i/j != j) cnt++;
      //     }
      //   }
      //   ans=max(ans, cnt);
      // }
      // cout<<"cnt="<<ans<<endl;
      for (int i = 1; i <= n; ++i) {
        set<int> ss;
        ss.clear();
        for (int j = 1; j <= n; ++j) {
          ss.insert(abs(a[j]-a[i]));
        }
        vector<int> ds(ss.begin(), ss.end());
        for (int j = 0; j < ds.size(); ++j) {
          vector<int> v;
          v.clear();
          for (int k = 1; k*k <= ds[j]; ++k) {
            if (ds[j]%k == 0) {
              v.push_back(k);
              if (ds[j] / k != k) {
                v.push_back(ds[j]/k);
              }
            }
          }
         // int cnt=0;
          for (int k = 0; k < v.size(); ++k) {
            int cnt=0;
            for (int i2=1; i2<=n; ++i2) {
              ll res = ((ll)a[i2] + 1000000LL*v[k]) % v[k];
              ll res2 = ((ll)a[i] + 1000000LL*v[k]) % v[k];
              if (res==res2) {
                cnt++;
              }
            }
            if (cnt>=n/2) ans=max(ans, v[k]);
          }
        }
      }
      // memset(cnt, 0, sizeof(cnt));
      // for (int i = 1000000; i >= 1; --i) {
      //   vector<int> tmp;
      //   tmp.clear();
      //   int mx = 0;
      //   for (int j = 1; j <= n; ++j) {
      //     ll res = ((ll)a[j] + 1000000LL*i) % i;
      //     //int res=a[j]%i;
      //     tmp.push_back(res);
      //     cnt[res]++;
      //     mx=max(mx, cnt[res]);
      //   }
      //   if (mx >= n/2) {
      //     ans=max(ans, i);
      //     break;
      //   }
      //   for (int j = 0; j < tmp.size(); ++j) {
      //     cnt[tmp[j]]--;
      //   }
      // }
      // for (int i = 1; i <= n; ++i) {
      //   for (int j = i+1; j <= n; ++j) {
      //     int det = abs(a[i]-a[j]);
      //     vector<int> ps;
      //     ps.clear();
      //     int x= det;
      //     for (int k = 2; k * k <= x; ++k) {
      //       if (x%k == 0) {
      //         ps.push_back(k);
      //         while(x%k == 0) {
      //           x/=k;
      //         }
      //       }
      //     }
      //     if (x>1) ps.push_back(x);
      //     for (int k = 0; k < ps.size(); ++k) {
      //       map<int,int>cnt;
      //       cnt.clear();
      //       int maxv=0;
      //       for (int k2 = 1; k2 <= n; ++k2) {
      //         ll res = ((ll)a[k2] + 1000000LL*ps[k]) % ps[k];
      //         cnt[res]++;
      //         maxv=max(maxv, cnt[res]);
      //       }
      //       //if (ps[k] == 13) cout<<"cnt="<<(*cnt.rbegin()<<endl;
      //       if (maxv>=n/2) {
      //         ans=max(ans, ps[k]);
      //       }
      //     }
      //   }
      // }
      printf("%d\n", ans);
    }
  }
  return 0;
}
