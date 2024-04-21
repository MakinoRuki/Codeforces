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
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
map<int,int> cnt[N];
ll ans;
// 不能直接并查集，因为同色同集合里有可能互相在往外走的路径上。
void dfs(int u, int p) {
  int id=-1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u);
    if (id < 0 || cnt[v].size() > cnt[id].size()) {
      id = v;
    }
  }
  if (id >= 0 && cnt[id].find(a[u]) != cnt[id].end()) {
    ans += cnt[id][a[u]];
  }
  // 注意合并map的技巧。
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p || v == id) continue;
    for (auto itr : cnt[v]) {
      if (itr.first == a[u]) {
        ans += itr.second;
      } else {
        ans += (ll)itr.second * (ll)cnt[id][itr.first];
      }
      cnt[id][itr.first] += itr.second;
    }
  }
  // 必须swap不能copy。
  if (id >= 0) swap(cnt[u], cnt[id]);
  cnt[u][a[u]] = 1;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i].clear();
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    ans=0LL;
    dfs(1, 0);
    printf("%lld\n", ans);
  }
  return 0;
}
