
#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
vector<pair<int,int>> edges[N];
ll dis[N];
int pre[N]; 
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    edges[i].clear();
    dis[i] = (1LL<<61)-1;
    pre[i] = 0;
  }
  for (int i =1; i <= m; ++i) {
    int u,v,w;
    scanf("%d%d%d", &u, &v, &w);
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, w));
  }
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
  dis[1] = 0;
  pq.push(make_pair(0, 1));
  while(!pq.empty()) {
    auto tp = pq.top();
    pq.pop();
    ll ds = tp.first;
    int u = tp.second;
    if (ds > dis[u]) {
      continue;
    }
    for (auto pr : edges[u]) {
      ll w = pr.second;
      int v = pr.first;
      if (dis[v] > dis[u] + w) {
        pre[v] = u;
        dis[v] = dis[u] + w;
        pq.push(make_pair(dis[v], v));
      }
    }
  }
  if (dis[n] >= (1LL<<61)-1) {
    puts("inf");
    return 0;
  }
  vector<pair<ll,int>> rk;
  rk.clear();
  for (int i = 2; i <= n; ++i) {
    rk.push_back(make_pair(dis[i], i));
  }
  sort(rk.begin(), rk.end());
  string s=string(n, '0');
  s[0]='1';
  vector<pair<string,ll>> vv;
  vv.clear();
  for (int i = 0; i < rk.size(); ++i) {
    ll dt = (i==0?rk[i].first:rk[i].first-rk[i-1].first);
    if (dt) {
      vv.push_back(make_pair(s, dt));
    }
    s[rk[i].second-1] = '1';
    if (rk[i].second == n) break;
  }
  printf("%lld %d\n", dis[n], (int)vv.size());
  for (auto pr : vv) {
    cout<<pr.first<<" ";
    printf("%lld\n", pr.second);
  }
  return 0;
}
