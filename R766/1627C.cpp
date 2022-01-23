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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
vector<pair<int,int>> edges[N];
int deg[N];
int ans[N];
void dfs(int u, int c) {
  int id;
  for (int i = 0; i < edges[u].size(); ++i) {
    if (ans[edges[u][i].second] < 0) {
      ans[edges[u][i].second] = c;
      dfs(edges[u][i].first, (5-c));
      break;
    }
  }
}
int main() {
  cin>>t;
  int r,c;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      deg[i] = 0;
      ans[i] = -1;
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(make_pair(v,i));
      edges[v].push_back(make_pair(u,i));
      deg[u]++;
      deg[v]++;
    }
    bool found=false;
    for (int i = 1; i <= n; ++i) {
      if (deg[i] > 2) {
        found=true;
        break;
      }
    }
    if (found) {
      puts("-1");
    } else {
      int id = 0;
      for (int i =1; i <= n; ++i) {
        if (deg[i] == 1) {
          id = i;
        }
      }
      dfs(id, 2);
      for (int i = 1; i < n; ++i) {
        printf("%d", ans[i]);
        if (i < n-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
