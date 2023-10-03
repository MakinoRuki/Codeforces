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
#define N 5002
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int p[N];
vector<int> edges[N];
ll tot;
int cnt[N];
int dfs(int u) {
  cnt[u] = 0;
  for (int i =0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    cnt[u] += dfs(v);
  }
  return cnt[u]+1;
}
int main() {
  cin>>n;
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &p[i]);
    edges[p[i]].push_back(i);
  }
  // if (n==5000 && p[3]==2) {
  //   for (int i = 1; i < n; ++i) {
  //     if (edges[i].size() != 1) {
  //       cout<<"!!!="<<i<<endl;
  //     }
  //   }
  // }
  tot = 0LL;
  dfs(1);
  for (int u = n; u >= 1; --u) {
   // cout<<u<<" "<<"cnt="<<cnt[u]<<endl;
    int sz = (int)edges[u].size();
    ll dp[2][N];
    for (int j = 0; j <= n; ++j) {
      dp[0][j] = dp[1][j] = -1;
    }
    dp[0][0] = 0;
    for (int i = 0; i < sz; ++i) {
      int v = edges[u][i];
      int now = i&1;
      int num=0;
      for (int j = 0; j <= cnt[u]; ++j) {
        dp[now^1][j] = -1;
      }
      for (int j = 0; j <= cnt[u]; ++j) {
        if (dp[now][j] >= 0) {
          int j2 = num-j;
          dp[now^1][j] = max(dp[now^1][j], dp[now][j]);
          if (j+cnt[v] <= cnt[u]) {
            dp[now^1][j+cnt[v]] = max(dp[now^1][j+cnt[v]], dp[now][j]);
          } 
        }
      }
      num += cnt[v];
    }
    ll tmp = 0LL;
    for (int i = 0; i <= cnt[u]; ++i) {
      if (dp[sz&1][i] >= 0) {
        tmp = max(tmp, (ll)i * (ll)(cnt[u]-i));
      }
    }
  //  cout<<u<<" "<<tmp<<endl;
    tot += tmp;
    cnt[u]++;
  }
  cout<<tot<<endl;
  return 0;
}
