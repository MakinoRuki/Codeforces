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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
vector<int> edges[N];
int col[N];
int c0, c1;
void dfs(int u, int p, int c) {
  if (col[u] >= 0) return;
  if (c == 0) c0++;
  else c1++;
  col[u] = c;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, !c);
  }
}
int main() {
  int x;
  cin>>n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(col, -1, sizeof(col));
  c0= 0, c1 = 0;
  dfs(1, 0, 0);
  ll res = (ll)c0 * (ll)c1 - (n-1);
  cout<<res<<endl;
  return 0;
}
