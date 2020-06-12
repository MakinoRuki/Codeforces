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
#define N 2002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<string> ss;
int par[N];
vector<int> edges[N];
int dp[N];
bool dfs(int u) {
  if (dp[u] == 0) return false;
  if (dp[u] > 0) return true;
  dp[u] = 0;
  int res=1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (!dfs(v)) return false;
    res = max(res, dp[v]+1);
  }
  dp[u] = res;
  return true;
}
int find(int u) {
  return u==par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>n>>m;
  ss.clear();
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    ss.push_back(s);
  }
  for (int i = 1; i <= n+m; ++i) {
    par[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ss[i][j] == '=') {
        int pi = find(i+1);
        int pj = find(n+j+1);
        if (pi != pj) {
          par[pi] = pj;
        }
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int pi, pj;
      if (ss[i][j] != '=') {
        pi = find(i+1);
        pj = find(n+j+1);
      } else {
        continue;
      }
      if (ss[i][j] == '>') {
        if (pi == pj) {
          ok = false;
          break;
        }
        edges[pi].push_back(pj);
      } else if (ss[i][j] == '<') {
        if (pi == pj) {
          ok = false;
          break;
        } else {
          edges[pj].push_back(pi);
        }
      }
    }
    if (!ok) break;
  }
  if (!ok) {
    cout<<"No"<<endl;
    return 0;
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n+m; ++i) {
    if (find(i) == i && dp[i]<0) {
      if (!dfs(i)) {
        ok = false;
        break;
      }
    }
  }
  if (!ok) {
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  for (int i = 1; i <= n; ++i) {
    printf("%d", dp[find(i)]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  for (int j = n+1; j <= n+m; ++j) {
    printf("%d", dp[find(j)]);
    if (j < n+m) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
