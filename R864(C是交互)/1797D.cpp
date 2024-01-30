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
#define N 100005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
set<pair<int,int>> ss[N];
int cnt[N];
ll sum[N];
int fa[N];
void dfs(int u, int p) {
    cnt[u] = 1;
    sum[u] = a[u];
    fa[u] = p;
   // cout<<"u="<<u<<" "<<p<<endl;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        sum[u] += sum[v];
        ss[u].insert(make_pair(-cnt[v], v));
    }
}
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ss[i].clear();
    edges[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int u,v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1, 0);
  while(m-->0) {
    int tp, x;
    scanf("%d%d", &tp, &x);
    if (tp == 1) {
        printf("%lld\n", sum[x]);
    } else {
        if (ss[x].empty()) {
            continue;
        }
        auto pr = *ss[x].begin();
        int v = pr.first;
        int id1 = pr.second;
        int id0 = fa[x];
        ss[x].erase(make_pair(-cnt[id1], id1));
        ss[id0].erase(make_pair(-cnt[x], x));
        sum[x] -= sum[id1];
        cnt[x] -= cnt[id1];
        ss[id1].insert(make_pair(-cnt[x], x));
        sum[id1] += sum[x];
        cnt[id1] += cnt[x];
        ss[id0].insert(make_pair(-cnt[id1], id1));
        fa[x] = id1;
        fa[id1] = id0;
    }
  }
  return 0;
}
