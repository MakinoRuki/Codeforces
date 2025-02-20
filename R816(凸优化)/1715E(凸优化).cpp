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
#include <stack>
#include <bitset>
#include <chrono>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
vector<pair<int,int>> edges[N];
ll dis[N];
struct CHT {
    struct line {
        ll k, b;
        line() {}
        line(ll k, ll b): k(k), b(b) {}
        
        double intersect(line l) {
            double db = l.b - b;
            double dk = k - l.k;
            return db / dk;
        }
        
        ll operator () (ll x) {
            return k * x + b;
        }
    };
    
    vector<double> x;
    vector<line> ls;
    
    void init(line l) {
        x.push_back(-1e18);
        ls.push_back(l);
    }
    
    void addLine(line l) {
        //插进第i条line，存储的x是第i和第i-1条line的交点。
        while (ls.size() >= 2 && l.intersect(ls[ls.size() - 2]) <= x.back()) {
            x.pop_back();
            ls.pop_back();
        }
        if (!ls.empty()) {
            x.push_back(l.intersect(ls.back()));
        }
        ls.push_back(l);
    }
    
    ll query(ll qx) {
        int id = upper_bound(x.begin(), x.end(), qx) - x.begin();
        --id;
        return ls[id](qx);
    }
};
void dij() {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] < (1LL<<61)) {
            pq.push(make_pair(dis[i], i));
        }
    }
    while(!pq.empty()) {
        auto pr = pq.top();
        pq.pop();
        ll d = pr.first;
        int u = pr.second;
        if (d > dis[u]) continue;
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i].first;
            ll w = edges[u][i].second;
            if (dis[v] > dis[u]+w) {
                dis[v] = dis[u]+w;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}
int main() {
  cin>>n>>m>>k;
  for (int i = 1; i <= n; ++i) {
      edges[i].clear();
  }
  for (int i = 1; i <= m; ++i) {
      int u,v,w;
      scanf("%d%d%d", &u, &v, &w);
      edges[u].push_back(make_pair(v, w));
      edges[v].push_back(make_pair(u, w));
  }
  for (int i = 1; i <= n; ++i) {
      dis[i] = (1LL<<61);
  }
  dis[1] = 0;
  dij();
  for (int i = 1; i <= k; ++i) {
      CHT cht;
      cht.init(CHT::line(-2, 1));
      for (int j = 2; j <= n; ++j) {
          cht.addLine(CHT::line(-2LL * j, dis[j]+(ll)j*(ll)j));
      }
      dis[1]=0;
      for (int j = 2; j <= n; ++j) {
          dis[j] = cht.query(j) + (ll)j*(ll)j;
         // cout<<"j="<<j<<" "<<dis[j]<<endl;
      }
      dij();
  }
  for (int i = 1; i <= n; ++i) {
      printf("%lld ", dis[i]);
  }
  cout<<endl;
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
