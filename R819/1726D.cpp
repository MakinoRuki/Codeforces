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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int par[N];
vector<pair<int,int>> edges[N];
vector<pair<int,int>> es;
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    es.clear();
    set<int> rv;
    set<int> bv;
    rv.clear();
    bv.clear();
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      par[i]=i;
    }
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      es.push_back(make_pair(u, v));
      edges[u].push_back(make_pair(v, i));
      edges[v].push_back(make_pair(u, i));
    }
    vector<int> tv;
    tv.clear();
    for (int i = 0; i < es.size(); ++i) {
      int u = es[i].first;
      int v = es[i].second;
      int pu=find(u);
      int pv=find(v);
      if (pu != pv) {
        par[pu] = pv;
        rv.insert(i+1);
      } else {
        tv.push_back(i+1);
        bv.insert(i+1);
      }
    }
    if (tv.size() > 2) {
      set<int> ss;
      ss.clear();
      for (int i = 0; i < tv.size(); ++i) {
        int id=tv[i];
        ss.insert(es[id-1].first);
        ss.insert(es[id-1].second);
      }
      if (ss.size() == 3) {
        int id1 = tv[0];
        int u = es[id1-1].first;
        int v = es[id1-1].second;
        bv.erase(id1);
        rv.insert(id1);
        for (int i = 0; i < m; ++i) {
          if (i+1 != id1 && ((es[i].first == u)||(es[i].second==u))) {
            if (rv.find(i+1) !=rv.end()) {
              rv.erase(i+1);
              bv.insert(i+1);
            }
          }
        }
        // for (int i = 0; i < edges[u].size(); ++i) {
        //   int id2 = edges[u][i].second;
        //   if (id2 != tv[0] && id2 != tv[1] && id2 != tv[2]) {
        //     rv.erase(id2);
        //     bv.insert(id2);
        //     break;
        //   }
        // }
      }
    }
    string ans(m, '1');
    for (auto itr : bv) {
      ans[itr-1] = '0';
    }
    cout<<ans<<endl;
  }
  return 0;
}
