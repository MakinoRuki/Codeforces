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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int d[N];
vector<pair<int,int>> edges[N];
int par[N];
int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}
int dfs(int u, int p, vector<int>& ans) {
  int res = 0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    if (v == p) continue;
    if (dfs(v, u, ans)) {
      ans.push_back(edges[u][i].second);
      res ^= 1;
    }
  }
  if (p == 0) {
    if (d[u] == -1) return 1;
    if (res != d[u]) return -1;
    return 1;
  } else {
    if (d[u] == -1) return 0;
    if (d[u] == res) return 0;
    return 1;
  }
}
int main() {
  cin>>n>>m;
  map<int, int> mp;
  mp.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
    par[i] = i;
    mp[d[i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
      par[pu] = pv;
      edges[u].push_back(make_pair(v, i));
      edges[v].push_back(make_pair(u, i));
    }
  }
  vector<int> ans;
  ans.clear();
  if (mp.find(-1) != mp.end()) {
    dfs(mp[-1], 0, ans);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d\n", ans[i]);
    }
  } else {
    if (mp.find(1) != mp.end() && dfs(mp[1], 0, ans)>=0) {
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
      }
    } else {
      ans.clear();
      if (mp.find(0) != mp.end() && dfs(mp[0], 0, ans)>=0) {
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); ++i) {
          printf("%d\n", ans[i]);
        }
      } else {
        puts("-1");
      }
    }
  }
  return 0;
}
