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
int t, n, m;
vector<int> edges[N];
int col[N];
void dfs(int u, int c) {
  col[u] = c;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (col[v] < 0) {
      dfs(v, !c);
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<= t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
      col[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
      if (col[i] < 0) {
        dfs(i, 0);
      }
    }
    vector<int> ans;
    ans.clear();
    int bc = 0;
    int wc = 0;
    for (int i = 1; i <= n; ++i) {
      if (col[i] == 0) wc++;
      else bc++;
    }
    if (wc <= n/2) {
      for (int i = 1; i <= n; ++i) {
        if (col[i] == 0) ans.push_back(i);
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (col[i] == 1) ans.push_back(i);
      }
    }
    cout<<ans.size()<<endl;
    for (int i = 1; i <= ans.size(); ++i) {
      printf("%d", ans[i-1]);
      if (i < ans.size()) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
