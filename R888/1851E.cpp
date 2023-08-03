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
#include <random>
#include <ctime>
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int deg[N];
ll ans[N];
vector<int> edges[N];
ll c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &c[i]);
      edges[i].clear();
      deg[i] = 0;
      ans[i] = 0;
    }
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
      int x;
      scanf("%d", &x);
      c[x] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      int z;
      scanf("%d", &z);
      deg[i] = z;
      for (int j = 0; j < z; ++j) {
        int v;
        scanf("%d", &v);
        edges[v].push_back(i);
      }
    }
    for (int i =1; i <= n; ++i) {
      if (deg[i] == 0) {
        q.push(i);
        ans[i] = c[i];
      }
    }
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      ans[u] = min(ans[u], c[u]);
      for (int i = 0; i < edges[u].size(); ++i) {
        int v=edges[u][i];
        deg[v]--;
        ans[v] += ans[u];
        if (deg[v] == 0) {
          q.push(v);
        }
      }
    }
    for (int i =1; i <= n; ++i) {
      printf("%lld", ans[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
