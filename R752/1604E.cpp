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
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int a[N];
ll dp[2][N][2];
vector<int> val[2];
int main() {
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < 2; ++i) {
    val[i].clear();
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans = 0LL;
    for (int i = n; i >= 1; --i) {
      int now = i&1;
      for (int j = 0; j < val[now].size(); ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[now][val[now][j]][k] = -1;
        }
      }
      val[now].clear();
      for (int j = 0; j < val[now^1].size(); ++j) {
        int x = val[now^1][j];
      //  if (i == 2) cout<<"x="<<x<<" "<<((a[i]+x-1)/x)<<endl;
        int y = a[i] / ((a[i]+x-1)/x);
     //   if (i == 1) cout<<x<<" "<<y<<" "<<dp[now^1][x][0]<<endl;
     //   if (i == 2) cout<<"y="<<a[i]<<" "<<y<<endl;
        if (y <= 0) continue;
        ll det = (dp[now^1][x][1] + dp[now^1][x][0]*(ll)((a[i]+x-1)/x-1) % mod2) % mod2;
        if (dp[now][y][0] < 0) {
          dp[now][y][0] = dp[now^1][x][0];
          dp[now][y][1] = det;
          val[now].push_back(y);
        } else {
          dp[now][y][0] = (dp[now][y][0] + dp[now^1][x][0]) % mod2;
          dp[now][y][1] = (dp[now][y][1] + det) % mod2;
        }
      //  if (i == 2 && x == 3 && y == 2) cout<<"v="<<dp[now^1][x]<<" "<<(ll)((a[i]+x-1)/x-1)<<endl;
        ans = (ans + det) % mod2;
      //  if (i == 2 && x == 3 && y == 2) cout<<"ans="<<ans<<endl;
      }
      if (dp[now][a[i]][0] < 0) {
        dp[now][a[i]][0] = 1;
        dp[now][a[i]][1] = 0;
        val[now].push_back(a[i]);
      } else {
        dp[now][a[i]][0] = (dp[now][a[i]][0] + 1) % mod2;
      }
      // for (int j = 0; j < val[now].size(); ++j) {
      //   ans = (ans + dp[now][val[now][j]]) % mod2;
      // }
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < val[i].size(); ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][val[i][j]][k] = -1;
        }
      }
      val[i].clear();
    }
    printf("%lld\n", ans);
  }
  return 0;
}
