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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<pair<int, pair<int,int>>> edges;
int par[N];
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>n>>m;
  edges.clear();
  for (int i = 1; i <= m; ++i) {
    int u,v,w;
    scanf("%d%d%d", &u, &v, &w);
    edges.push_back(make_pair(w, make_pair(u,v)));
  }
  sort(edges.begin(), edges.end());
  int ans=0;
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
  }
  int i = 0;
  while(i < m) {
    int j = i;
    for (j = i; j < m; ++j) {
      if (edges[j].first != edges[i].first) break;
    }
    vector<int> ids;
    ids.clear();
    for (int k = i; k < j; ++k) {
      int u = edges[k].second.first;
      int v = edges[k].second.second;
      int pu = find(u);
      int pv = find(v);
      if (pu != pv) {
        ids.push_back(k);
      }
    }
    for (int k = 0; k < ids.size(); ++k) {
      int id = ids[k];
      int u = edges[id].second.first;
      int v = edges[id].second.second;
      int pu = find(u);
      int pv = find(v);
      if (pu != pv) {
        par[pu] = pv;
      } else {
        ans++;
      }
    }
    i = j;
  }
  cout<<ans<<endl;
  return 0;
}
