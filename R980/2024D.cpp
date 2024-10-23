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
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<pair<int,int>> edges[N];
ll dis[N];
bool vis[N];
void bfs() {
  dis[1] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  q.push(make_pair(dis[1], 1));
  while(!q.empty()) {
    auto pr = q.top();
    q.pop();
    int u = pr.second;
    ll d = pr.first;
    //cout<<"ud="<<u<<" "<<d<<endl;
    if (d > dis[u]) continue;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i].first;
      ll w = edges[u][i].second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u]+w;
        q.push(make_pair(dis[v], v));
      }
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      edges[i].clear();
      dis[i] = (1LL<<61)-1;
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      edges[i].push_back(make_pair(x, a[i]));
      edges[i].push_back(make_pair(i-1, 0));
    }
    bfs();
    ll ans = 0LL;
    ll sum=0LL;
    for (int i = 1; i <= n; ++i) {
      sum += a[i];
      ans = max(ans, sum-dis[i]);
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

