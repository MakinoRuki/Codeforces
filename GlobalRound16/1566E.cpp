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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<int> edges[N];
int ans;
int dfs(int u, int p, int& ln, int& bn) {
  if (edges[u].size() == 1 && edges[u][0] == p) {
    return 1;
  }
  int cnt=0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    int res = dfs(v, u, ln, bn);
    if (res == 1) {
      cnt++;
    }
  }
  if (u == 1) {
    ans = ln-(bn-1);
    if (cnt > 0) {
      ans += cnt-1;
    }
    return 2;
  } else {
    if (cnt > 0) {
      bn++;
      ln += cnt;
      return 2;
    }
    return 1;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    ans = 0;
    int ln=0, bn = 0;
    dfs(1, 0, ln, bn);
    printf("%d\n", ans);
  }
  return 0;
}
