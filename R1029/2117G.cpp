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
#define N 500005
#define M 10002
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
// int a[N];
// int b[N];
// int c[N];
vector<pair<int,int>> edges[N];
vector<pair<int,pair<int,int>>> es;
int par[N];
int wws[N];
int find(int x) {
  return x==par[x]?x:par[x]=find(par[x]);
}
bool check() {
  int p1 = find(1);
  int pn = find(n);
  return p1 == pn;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
   // ll a,b,c,m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      par[i]=i;
      wws[i]=inf;
    }
    es.clear();
    for (int i = 1; i <= m; ++i) {
      int u,v,w;
      scanf("%d%d%d", &u, &v, &w);
      es.push_back(make_pair(w, make_pair(u,v)));
    }
    sort(es.begin(), es.end());
    ll ans= (1LL<<61)-1;
    for (auto pr : es) {
      int w = pr.first;
      int u=pr.second.first;
      int v=pr.second.second;
      int pu=find(u);
      int pv=find(v);
      if (pu != pv) {
       // ll ww = min(wws[pu], wws[pv]);
        wws[pu] = min(wws[pu], min(w, wws[pv]));
        par[pv] = pu;
      }
      if (check()) {
        ans = min(ans, (ll)w + (ll)wws[find(1)]);
      }
    }
    printf("%lld\n", ans);
  }

  

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
