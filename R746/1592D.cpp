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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int d;
vector<int> edges[N];
int t;
bool vis[N];
int cnt[N];
int rem;
void dfs(int u, int p, vector<pair<int,int>>& ids) {
  if (p) ids.push_back(make_pair(p, u));
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, ids);
  }
}
int main() {
  cin>>n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(vis, false, sizeof(vis));
  printf("? %d", n);
  for (int i = 1; i <= n; ++i) {
    printf(" %d", i);
  }
  cout<<endl;
  fflush(stdout);
  int res=0;
  scanf("%d", &res);
  int u = 1, p = 0;
  rem=n;
  vector<pair<int,int>> ids;
  ids.clear();
  dfs(1, 0, ids);
  int l = 0, r = (int)ids.size()-1;
  while(l < r) {
    int mid = (l+r)/2;
    set<int> ss;
    ss.clear();
    for (int i = l; i <= mid; ++i) {
      ss.insert(ids[i].first);
      ss.insert(ids[i].second);
    }
    printf("? %d", (int)ss.size());
    for (auto v : ss) {
      printf(" %d", v);
    }
    cout<<endl;
    fflush(stdout);
    int tmp=0;
    scanf("%d", &tmp);
    if (tmp == res) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  printf("! %d %d\n", ids[r].first, ids[r].second);
  return 0;
}
