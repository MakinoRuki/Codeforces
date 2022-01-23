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
#define M 500005
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
int a[N];
vector<vector<int>> ss;
vector<int> edges[N];
int st[N];
bool vis[N];
int main() {
  cin>>n>>m;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    vector<int> cur;
    cur.clear();
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      int x;
      scanf("%d", &x);
      cur.push_back(x);
    }
    ss.push_back(cur);
  }
  memset(st, -1, sizeof(st));
  memset(vis, false, sizeof(vis));
  bool ok = true;
  for (int i = 0; i < ss.size()-1; ++i) {
    int j = 0;
    for (j = 0; j < min(ss[i].size(), ss[i+1].size()); ++j) {
      if (ss[i][j] != ss[i+1][j]) {
        break;
      }
    }
    if (j < min(ss[i].size(), ss[i+1].size())) {
      if (ss[i][j] < ss[i+1][j]) {
        edges[ss[i+1][j]].push_back(ss[i][j]);
      } else {
        if (st[ss[i][j]] == 0) {
          ok=false;
          break;
        } else {
          st[ss[i][j]] = 1;
        }
        if (st[ss[i+1][j]] == 1) {
          ok=false;
          break;
        } else {
          st[ss[i+1][j]]= 0;
        }
      }
    } else {
      if (ss[i].size() > ss[i+1].size()) {
        ok=false;
        break;
      }
    }
  }
  if (!ok) {
    puts("No");
    return 0;
  }
  queue<int> q;
  
  vector<int> ans;
  ans.clear();
  for (int i = 1; i <= m; ++i) {
    if (st[i] == 1) {
      q.push(i);
      vis[i] = true;
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if (st[u] == 0) {
      ok=false;
      break;
    }
    ans.push_back(u);
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (!vis[v]) {
        q.push(v);
        vis[v] = true;
      }
    }
  }
  if (!ok) {
    puts("No");
  } else {
    puts("Yes");
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
