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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll inf = (1LL<<61)-1;
int n, m, k;
int t;
int a[2][N];
ll dp1[N][2][2];
ll dp2[N][2][2];
ll getres(int j1, int j2, int s1, int s2, int k1, int k2) {
  if (k1 == 0 && k2 == 0) {
    if (s1+s2+j1+j2==0) {
      return 0;
    }
    return inf;
  } else if (k1 && k2) {
    ll add = inf;
    if ((j1|s1) && (j2|s2)) {
      add = (j1 ? 1 : 0) + (j2 ? 1 : 0);
    }
    if (j1==0 && s1==0) {
      if (j2 && s2) add = 2;
    }
    if (j2 == 0 && s2 == 0) {
      if (j1 && s1) add = 2;
    }
    return add;
  } else if (k1 && !k2) {
    if (j1+j2+s1+s2==0) return inf;
    ll add =0;
    if (j1+j2+s2 == 3) add= 3;
    else if (j1 + j2 + s2 == 2) add = 2;
    else if (j1+j2+s2 == 1) {
      if (j2) add = 2;
      else add = 1;
    }
    return add;
  } else {
    if (j1+j2+s1+s2==0) return inf;
    ll add =0;
    if (j1+j2+s1 == 3) add= 3;
    else if (j1 + j2 + s1 == 2) add = 2;
    else if (j1+j2+s1 == 1) {
      if (j1) add = 2;
      else add = 1;
    }
    return add;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> ids[2];
    int b = -1, e = -1;
    int n0 = 0, n1 = 0;
    for (int i = 0; i < 2; ++i) {
      string s;
      cin>>s;
      ids[i].clear();
      for (int j = 1; j <= n; ++j) {
        if (s[j-1] == '*') {
          a[i][j] = 1;
          ids[i].push_back(j);
          if (b < 0) b = j;
          else b = min(b, j);
          if (e < 0) e = j;
          else e = max(e, j);
          if (i == 0)n0++;
          else n1++;
       //   cout<<"j="<<j<<" "<<b<<" "<<e<<endl;
        } else a[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp1[i][j][k] = inf;
          dp2[i][j][k] = inf;
        }
      }
    }
    if (a[0][1] && a[1][1]) {
      dp1[1][0][1] = 1;
      dp1[1][1][0] = 1;
      dp1[1][1][1] = 0;
    } else if (a[0][1] && !a[1][1]) {
      dp1[1][1][0] = 0;
      dp1[1][0][1] = 1;
    } else if (!a[0][1] && a[1][1]) {
      dp1[1][0][1] = 0;
      dp1[1][1][0] = 1;
    } else {
      dp1[1][0][0] = 0;
    }
    for (int i = 1; i < n; ++i) {
      for (int j1 = 0; j1 < 2; ++j1) {
        for (int j2 = 0; j2 < 2; ++j2) {
          if (dp1[i][j1][j2] < inf) {
            int s1 = a[0][i+1];
            int s2 = a[1][i+1];
            for (int k1 = 0; k1 < 2; ++k1) {
              for (int k2 = 0; k2 < 2; ++k2) {
                ll res = getres(j1, j2, s1, s2, k1, k2);
                if (res < inf) {
                  dp1[i+1][k1][k2] = min(dp1[i+1][k1][k2], dp1[i][j1][j2] + res);
                }
              }
            }
          }
        }
      }
    }
    if (a[0][n] && a[1][n]) {
      dp2[n][0][1] = 1;
      dp2[n][1][0] = 1;
      dp2[n][1][1] = 0;
    } else if (a[0][n] && !a[1][n]) {
      dp2[n][1][0] = 0;
      dp2[n][0][1] = 1;
    } else if (!a[0][n] && a[1][n]) {
      dp2[n][0][1] = 0;
      dp2[n][1][0] = 1;
    } else {
      dp2[n][0][0] = 0;
    }
    for (int i = n; i > 1; --i) {
      for (int j1 = 0; j1 < 2; ++j1) {
        for (int j2 = 0; j2 < 2; ++j2) {
          if (dp2[i][j1][j2] < inf) {
            int s1 = a[0][i-1];
            int s2 = a[1][i-1];
            for (int k1 = 0; k1 < 2; ++k1) {
              for (int k2 = 0; k2 < 2; ++k2) {
                ll res = getres(j1, j2, s1, s2, k1, k2);
                if (res < inf) {
                  dp2[i-1][k1][k2] = min(dp2[i-1][k1][k2], dp2[i][j1][j2] + res);
                 // if (k1 && k2 && dp2[2][1][1] < 2) cout<<"j="<<j1<<" "<<j2<<" "<<dp2[3][j1][j2]<<" "<<res<<endl;
                }
              }
            }
          }
        }
      }
    }
    ll ans=min(dp1[n][0][1], dp1[n][1][0]);
    ans = min(ans, min(dp2[1][0][1], dp2[1][1][0]));
    for (int i = 1; i < n; ++i) {
      for (int j1 = 0; j1 < 2; ++j1) {
        for (int j2 = 0; j2 < 2; ++j2) {
          for (int k1 = 0; k1 < 2; ++k1) {
            for (int k2 = 0; k2 < 2; ++k2) {
              if (dp1[i][j1][j2] < inf && dp2[i+1][k1][k2] < inf) {
                int s = j1+j2+k1+k2;
                ll add = inf;
                if (s == 1) {
                  add = 0;
                } else if (s == 2) {
                  if ((k2 && j1) || (j2 && k1)) {
                    add = 2;
                  } else {
                    add = 1;
                  }
                } else if (s == 3) {
                  add = 2;
                } else if (s == 4) {
                  add = 3;
                }
               // if (dp1[i][j1][j2] + dp2[i+1][k1][k2] + add < 5) cout<<"i="<<i<<" "<<j1<<" "<<j2<<" "<<k1<<" "<<k2<<" "<<dp1[i][j1][j2]<<" "<<dp2[i+1][k1][k2]<<" "<<add<<endl;
                if (add < inf) ans = min(ans, dp1[i][j1][j2] + dp2[i+1][k1][k2] + add);
              }
            }
          }
        }
      }
    }
    printf("%lld\n", ans);
    // int ans = inf;
    // for (int i = 1; i <= n; ++i) {

    // }
   // cout<<b<<" "<<e<<endl;
    // int dt = ((n0 && n1) ? 1 : 0);
    // printf("%d\n", e - b + dt);
  }
  return 0;
}
