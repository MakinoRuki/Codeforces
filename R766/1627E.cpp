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
int x[N];
vector<pair<int,int>> edges[N];
int a[N], b[N], c[N], d[N], h[N];
ll dis[N];
vector<pair<int,int>> edges2[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      edges2[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x[i]);
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d%d%d%d%d", &a[i], &b[i], &c[i], &d[i], &h[i]);
      edges[a[i]].push_back(make_pair(b[i], i));
      edges2[c[i]].push_back(make_pair(d[i], i));
      dis[i] = (1LL<<60)-1;
    }
    for (int i =1; i <= n; ++i) {
      sort(edges2[i].begin(), edges2[i].end());
      sort(edges[i].begin(), edges[i].end());
    }
    ll ans = (1LL<<60)-1;
    c[0] = 1, d[0] = 1;
    edges2[1].push_back(make_pair(1, 0));
    dis[0] = 0;
   // cout<<"sz="<<edges[2].size()<<" "<<edges2[2].size()<<endl;
    for (int i = 1; i <= n; ++i) {
      vector<pair<int,int>> v1;
      vector<pair<int,int>> v2;
      for (int j = 0; j < edges2[i].size(); ++j) {
      //  int id = edges2[i][j].second;
        v1.push_back(edges2[i][j]);
      }
      for (int j = 0; j < edges[i].size(); ++j) {
      // int id = edges[i][j].second;
        v2.push_back(edges[i][j]);
      }
      // vector<int> stk;
      // stk.clear();
      int cur = 0;
      ll pre = (1LL<<60)-1;
      int id = -1;
      for (int j = 0; j < v2.size(); ++j) {
        int id2 = v2[j].second;
        while(cur < v1.size() && v1[cur].first <= b[id2]) {
          int id1 = v1[cur].second;
          if (dis[id1] < (1LL<<60)-1) {
            if (id < 0 || dis[id1] + (ll)abs(d[id1]-b[id2]) * (ll)x[i] < dis[id]+(ll)abs(d[id]-b[id2]) * (ll)x[i]) {
             // pre = dis[id1] + (ll)abs(d[id1]-b[id2]) * (ll)x[i];
              id = id1;
            }
          }
          cur++;
          // while(!stk.empty()) {
          //   int id0 = stk.back();
          //   if (dis[id0] + abs(d[id0]-b[id2])*x[i] >= dis[id1]+abs(d[id1]-b[id2]) * x[i]) {
          //     stk.pop_back();
          //   } else {
          //     break;
          //   }
          // }
          // stk.push_back()
        }
        if (id >= 0) {
          dis[id2] = min(dis[id2], dis[id]+(ll)abs(d[id]-b[id2]) * (ll)x[i] - (ll)h[id2]);
        }
        // if (i == 3) {
        //   cout<<"cur="<<cur<<" "<<dis[2]<<" "<<dis[3]<<endl;
        // }
      }
      pre = (1LL<<60)-1;
      cur = v1.size()-1;
      id = -1;
      for (int j = v2.size()-1; j >= 0; --j) {
        int id2 = v2[j].second;
        while(cur >= 0 && v1[cur].first >= b[id2]) {
          int id1 = v1[cur].second;
          if (dis[id1] < (1LL<<60)-1) {
          //  if (i == 3) cout<<"x="<<dis[id1]<<" "<<d[id1]<<" "<<b[id2]<<" "<<x[i]<<endl;
            if (id < 0 || dis[id1] + (ll)abs(d[id1]-b[id2]) * (ll)x[i] < dis[id]+(ll)abs(d[id]-b[id2]) * (ll)x[i]) {
             // pre = min(pre, dis[id1] + (ll)abs(d[id1]-b[id2]) * (ll)x[i]);
              id = id1;
            }
          //  if (i == 3) cout<<"y="<<pre<<endl;
          }
          cur--;
        }
        if (id >= 0) {
          dis[id2] = min(dis[id2], dis[id]+(ll)abs(d[id]-b[id2]) * (ll)x[i]-(ll)h[id2]);
        }
        // if (i == 3) {
        //   cout<<"cur2="<<cur<<" "<<dis[2]<<" "<<dis[3]<<endl;
        // }
      }
    }
    // for (int i = 1; i <= k; ++i) {
    //   cout<<"v="<<i<<" "<<dis[i]<<endl;
    // }
    // cout<<"sz="<<edges2[n].size()<<endl;
    // cout<<"ans="<<ans<<endl;
    for (int i = 0; i < edges2[n].size(); ++i) {
      int id = edges2[n][i].second;
      if (dis[id] < (1LL<<60)-1) {
      //  cout<<"id="<<id<<" "<<dis[id]<<" "<<d[id]-m<<" "<<x[n]<<endl;
        ans = min(ans, dis[id] + (ll)abs(d[id]-m) * (ll)x[n]);
      }
    }
    if (ans < (1LL<<60)-1) printf("%lld\n", ans);
    else puts("NO ESCAPE");
  }
  return 0;
}
