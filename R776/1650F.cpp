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
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<int> ops[N];
int dp[N][202];
int id[N][202];
int tm[N], p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ops[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int e;
      scanf("%d%d%d", &e, &tm[i], &p[i]);
      ops[e].push_back(i);
    }
    vector<int> ans;
    ans.clear();
    bool ok = true;
    ll tot=0;
    for (int i = 1; i <= n; ++i) {
    //  cout<<"i="<<i<<endl;
      for (int j = 0; j <= ops[i].size(); ++j) {
        for (int j2 = 0; j2 <= 200; ++j2) {
          dp[j][j2] = inf + 100;
        }
      }
      dp[0][0] = 0;
      for (int j = 0; j < ops[i].size(); ++j) {
        for (int j2 = 0; j2 <= 200; ++j2) {
          if (dp[j][j2] < inf + 100) {
            if (j2 < 100) {
              int j3 = j2 + p[ops[i][j]];
              if (dp[j][j2] + tm[ops[i][j]] < dp[j+1][j3]) {
                dp[j+1][j3] = dp[j][j2] + tm[ops[i][j]];
                id[j+1][j3] = j+1;
              }
            }
            if (dp[j][j2] < dp[j+1][j2]) {
              dp[j+1][j2] = dp[j][j2];
              id[j+1][j2] = id[j][j2];
            }
          }
        }
      }
      
      int mnv = inf + 100;
      int mnp = 100;
      for (int j = 100; j <= 200; ++j) {
        if (dp[ops[i].size()][j] < mnv) {
          mnv = dp[ops[i].size()][j];
          mnp = j;
        }
      }
    //  if (i == 2) cout<<"tot="<<tot<<" "<<dp[ops[i].size()][mnp]<<" "<<id[ops[i].size()][mnp]<<endl;
      if (mnv < inf + 100 && tot + mnv <= a[i]) {
        vector<int> tmp;
        tmp.clear();
        int x = (int)ops[i].size();
        int y = mnp;
        while(y > 0) {
          int cur = id[x][y];
          tmp.push_back(ops[i][cur-1]);
          x = cur - 1;
          y -= p[ops[i][cur-1]];
        }
        for (int j = tmp.size()-1; j >= 0; --j) {
          ans.push_back(tmp[j]);
        }
        tot += (ll)dp[ops[i].size()][mnp];
      } else {
        ok = false;
        break;
      }
    //  cout<<"i2="<<i<<endl;
    }
    if (!ok) puts("-1");
    else {
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i < ans.size()-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
