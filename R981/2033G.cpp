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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 510
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p, q;
int t;
int a[N];
vector<int> edges[N];
int par[N];
int dep[N];
int dp1[N][20];
int dp2[N][20];
int lw[N][4];
// int calc(int u, int d) {
//     for (int i = 19; i >= 0; --i) {
//         if ((1<<i) & d) {
//             u = dp[u][i];
//             if (u <= 0) return u;
//         }
//     }
//     return u;
// }
int dfs(int u, int p, int d) {
    par[u] = dp1[u][0] = p;
    dep[u] = d;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (v == p) continue;
        int res = dfs(v, u, d+1);
        if (res+1 > lw[u][1]) {
            lw[u][2] = lw[u][0];
            lw[u][3] = lw[u][1];
            lw[u][0] = v;
            lw[u][1] = res+1;
        } else if (res+1 > lw[u][3]) {
            lw[u][2] = v;
            lw[u][3] = res+1;
        }
    }
    if (lw[u][0] < 0) return 0;
    return lw[u][1];
}

int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
        for (int j = 0; j < 20; ++j) {
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
        lw[i][0] = lw[i][1] = lw[i][2] = lw[i][3] = -1;
    }
    for (int i =1 ; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp1[j][i-1] > 0 && dp1[dp1[j][i-1]][i-1] > 0) {
                dp1[j][i] = dp1[dp1[j][i-1]][i-1];
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        int p = par[i];
      //  if (i == 5) cout<<"p="<<p<<" "<<lw[p][0]<<" "<<lw[p][1]<<" "<<lw[p][2]<<" "<<lw[p][3]<<endl;
        if (lw[p][0] == i) {
            if (lw[p][2] > 0) dp2[i][0] = lw[p][3]+1;
            else dp2[i][0] = 1;
        } else {
            dp2[i][0] = lw[p][1] + 1;
        }
    }
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            int pp = dp1[j][i-1];
            dp2[j][i] = (1<<i);
            if (dp2[j][i-1] > 0) {
                dp2[j][i] = max(dp2[j][i], dp2[j][i-1]);
            }
            if (pp > 0 && dp2[pp][i-1] > 0) {
                dp2[j][i] = max(dp2[j][i], dp2[pp][i-1] + (1<<(i-1)));
            }
        }
    }
   // cout<<"v="<<dp2[4][0]<<endl;
   // cout<<"v="<<dp2[2][1]<<" "<<dp2[7][0]<<endl;
    scanf("%d", &q);
    vector<int> vv;
    vv.clear();
    while(q-->0) {
        int v, k;
        scanf("%d%d", &v, &k);
        k = min(k, dep[v]);
        int ans = max(0, lw[v][1]);
        int u = v;
        int cur=0;
        for (int i = 19; i >= 0; --i) {
            if ((1<<i) & k) {
                if (dp2[u][i]>0) {
                    ans = max(ans, dp2[u][i] + cur);
                    cur += (1<<i);
                    u = dp1[u][i];
                } 
            }
        }
        vv.push_back(ans);
    }
    for (auto x : vv) {
        printf("%d ", x);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

