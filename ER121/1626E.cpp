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
#define M 52
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
int c[N];
vector<int> edges[N];
int cnt0[N];
int cnt1[N];
int cnt2[N];
bool ans[N];
void dfs1(int u, int p) {
  bool found=false;
  if (c[u]) cnt1[u]++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs1(v, u);
    if (c[v]) cnt0[u]++;
    cnt1[u] += cnt1[v];
    cnt2[u] += cnt2[v];
  }
  if (c[u] && cnt1[u] > 1) cnt2[u]++;
  if (!c[u] && cnt0[u]>0 && cnt1[u] > 1) cnt2[u]++;
}
void dfs2(int u, int p, int ps) {
  if (c[u] && p > 0) {
    return ;
  }
  bool ok = false;
  bool found1=false;
  bool found2=false;
  int cur=0;
  if (!c[u]) {
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (v == p) continue;
      if (c[v]) {
        found1=true;
        break;
      }
      if (cnt2[v]) {
        found2=true;
        break;
      }
    }
    if (found1 || found2 || c[p]) {
      ok=true;
    } else if (ps) {
      ok=true;
    }
    if (!ok) ans[u]= false;
  }
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    int add = 0;
    if (!c[v]) {
      if (c[p] && cnt1[u]-cnt1[v] > 0) {
        add = 1;
      } else if (cnt0[u]) {
        add = 1;
      } else if (cnt2[u] - cnt2[v] > 0) {
        add  =1;
      }
    }
    dfs2(v, u, ps | add);
  }
}
int main() {
  cin>>n;
  int root=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
    if (c[i] == 1 && !root) {
      root = i;
    }
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(cnt0, 0, sizeof(cnt0));
  memset(cnt1, 0, sizeof(cnt1));
  memset(cnt2, 0, sizeof(cnt2));
  dfs1(root, 0);
  int cnt=0;
  int id = 0;
  for (int i = 0; i < edges[root].size(); ++i) {
    int v  = edges[root][i];
    if (cnt1[v] > 0) {
      cnt++;
      id = v;
    }
  }
  memset(ans, true, sizeof(ans));
  if (cnt  == 1 ) dfs2(id, root, 0);
  for (int i = 1; i <= n; ++i) {
    printf("%d", ans[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
