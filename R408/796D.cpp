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
int n, m, k;
int d;
bool p[N];
vector<pair<int,int>> edges[N];
int dis[N];
bool pick[N];
int main() {
  cin>>n>>k>>d;
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    dis[i] = inf;
  }
  memset(pick, false, sizeof(pick));
  memset(p, false, sizeof(p));
  for (int i = 1; i <= k; ++i) {
    int x;
    scanf("%d", &x);
    p[x] = true;
    dis[x] = 0;
    q.push(x);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(make_pair(v, i));
    edges[v].push_back(make_pair(u, i));
  }
  while(!q.empty()) {
    auto u = q.front();
    q.pop();
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i].first;
      int id = edges[u][i].second;
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
        pick[id] = true;
      }
    }
  }
  vector<int> ans;
  ans.clear();
  for (int i = 1; i < n; ++i) {
    if (!pick[i]) {
      ans.push_back(i);
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
