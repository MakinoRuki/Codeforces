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
int h[N];
vector<pair<int,int>> es;
vector<pair<pair<int,int>, pair<int,int>>> qs;
int ans[N];
int par[N];
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &h[i]);
      par[i] = i;
    }
    es.clear();
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      es.push_back(make_pair(u, v));
    }
    scanf("%d", &q);
    qs.clear();
    for (int i = 1; i <= q; ++i) {
      int a,b,e;
      scanf("%d%d%d", &a, &b, &e);
      qs.push_back(make_pair(make_pair(a,b), make_pair(e,i)));
    }
    sort(es.begin(), es.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
      return max(h[x.first], h[x.second]) < max(h[y.first], h[y.second]);
    });
    sort(qs.begin(), qs.end(), [](const pair<pair<int,int>,pair<int,int>>& x, const pair<pair<int,int>,pair<int,int>>& y) {
      return h[x.first.first]+x.second.first < h[y.first.first]+y.second.first;
    });
    int j = 0;
    for (int i = 0; i < qs.size(); ++i) {
      int u = qs[i].first.first;
      int v = qs[i].first.second;
      int e = qs[i].second.first;
      int id = qs[i].second.second;
      while(j < es.size() && max(h[es[j].first], h[es[j].second]) <= h[u] + e) {
        int px = find(es[j].first);
        int py = find(es[j].second);
        if (px != py) {
          par[px] = py;
        }
        j++;
      }
      int pu = find(u);
      int pv = find(v);
      if (pu == pv) {
        ans[id] = 1;
      } else {
        ans[id] = 0;
      }
    }
    for (int i = 1; i <= q; ++i) {
      if (ans[i]) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}
