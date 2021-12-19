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
#define N 600
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
vector<int> edges[N];
int deg[N];
int toposort() {
  queue<int> q;
  int deg2[N];
  for (int i = 1; i <= n; ++i) {
    if (deg[i] <= 0) {
      q.push(i);
    }
    deg2[i] = deg[i];
  }
  int tot=0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    tot++;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      deg2[v]--;
      if (deg2[v] == 0) {
        q.push(v);
      }
    }
  }
  return tot;
}
int main() {
  cin>>n>>m;
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    deg[v]++;
  }
  int res = toposort();
  if (res == n) {
    puts("YES");
    return 0;
  }
  bool found=false;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] > 0) {
      deg[i]--;
      int res = toposort();
      if (res == n) {
        found=true;
        break;
      }
      deg[i]++;
    }
  }
  if (found) puts("YES");
  else puts("NO");
  return 0;
}
