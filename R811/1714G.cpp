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
#define M 100005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
vector<pair<int,pair<int,int>>> edges[N];
ll dp[N][21];
ll sum[2][N];
int dep[N];
void dfs(int u, int p, int d, ll s1, ll s2) {
  dep[u] = d;
  sum[0][u] = s1;
  sum[1][u] = s2;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    ll d1 = edges[u][i].second.first;
    ll d2 = edges[u][i].second.second;
    dfs(v, u, d+1, s1+d1, s2+d2);
  }
}
ll getds(int u, int d) {
  ll tot=sum[1][u];
  for (int i = 20; i >= 0; --i) {
    if (dp[u][i]>0 && (1<<i)<=d) {
      u = dp[u][i];
      d -= (1<<i);
    }
  }
  return tot - sum[1][u];
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      for (int j = 0; j <= 20; ++j) {
        dp[i][j] = -1;
      }
    }
    for (int i = 2; i <= n; ++i) {
      int p, x, y;
      scanf("%d%d%d", &p, &x, &y);
      edges[p].push_back(make_pair(i, make_pair(x, y)));
      dp[i][0] = p;
    }
    dfs(1, 0, 0, 0LL, 0LL);
    for (int j = 1; j <= 20; ++j) {
      for (int i = 1; i <= n; ++i) {
        if (dp[i][j-1] > 0 && dp[dp[i][j-1]][j-1] > 0) {
          dp[i][j] = dp[dp[i][j-1]][j-1];
        }
      }
    }
    for (int i = 2; i <= n; ++i) {
      int l = 0, r = dep[i];
      while(l < r) {
        int mid=(l+r+1)/2;
        if (sum[1][i]-getds(i, dep[i]-mid) <= sum[0][i]) {
          l = mid;
        } else {
          r = mid-1;
        }
      }
      printf("%d", r);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
