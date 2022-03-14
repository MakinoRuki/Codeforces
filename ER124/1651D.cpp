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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int cnt[N];
map<pair<int,int>, int> idx;
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dp[N];
int dpx[N], dpy[N];
vector<pair<int,int>> ps;
vector<int> edges[N];
bool vis[N];
int main() {
  cin>>n;
  idx.clear();
  int cnt=0;
  ps.clear();
  for (int i = 1; i <= n; ++i) {
    int x,y;
    scanf("%d%d", &x, &y);
    ps.push_back(make_pair(x, y));
    idx[make_pair(x, y)] = i;
  }
  queue<int> q;
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    dp[i] = inf;
    dpx[i] = -1, dpy[i] = -1;
    int x = ps[i-1].first, y = ps[i-1].second;
    bool found=false;
    for (int d = 0; d < 4; ++d) {
      int nx = x+dx[d];
      int ny = y+dy[d];
      if (idx.find(make_pair(nx, ny)) == idx.end()) {
        int res = abs(nx-x) + abs(ny-y);
        if (res < dp[i]) {
          dp[i] = res;
          dpx[i] = nx;
          dpy[i] = ny;
        }
        found=true;
      } else {
        int id2 = idx[make_pair(nx, ny)];
        edges[id2].push_back(i);
        edges[i].push_back(id2);
      }
    }
    if (found) {
      q.push(i);
      vis[i] = true;
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    int x1 = ps[u-1].first;
    int y1 = ps[u-1].second;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      int x2 = ps[v-1].first;
      int y2 = ps[v-1].second;
      int res = abs(x1-x2) + abs(y1-y2);
      if (dp[u] + res < dp[v]) {
        dp[v] = dp[u] + res;
        dpx[v] = dpx[u];
        dpy[v] = dpy[u];
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
  //  cout<<"i="<<i<<" "<<dp[i]<<endl;
    printf("%d %d\n", dpx[i], dpy[i]);
  }
  return 0;
}
