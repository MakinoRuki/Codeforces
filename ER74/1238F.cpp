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
int t, n, m, k;
vector<int> edges[N];
int ans;
int dfs(int u, int p) {
  int tot=0;
  vector<int> rk;
  rk.clear();
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    tot++;
    rk.push_back(dfs(v, u));
  }
  sort(rk.begin(), rk.end());
  if (rk.empty()) {
    ans = max(ans, 1 + (p == 0 ? 0 : 1));
    return 1;
  } else if (rk.size() == 1) {
    ans = max(ans, rk[0]+1 + (p == 0 ? 0 : 1));
    return rk[0]+1;
  } else {
    ans = max(ans, rk[tot-1] + rk[tot-2] + 1 + tot - 2 + (p == 0 ? 0 : 1));
    return rk.back() + tot;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
    ans = 1;
    dfs(1, 0);
    printf("%d\n", ans);
  }
  return 0;
}
