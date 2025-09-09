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
#define N 600005
#define M 5002
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
vector<pair<pair<int,int>,int>> edges[N];
ll dp[N][2];
int main() {
//  freopen("data.txt", "r", stdin);
  cin>>n>>m;
  for (int i = 1; i <= m; ++i) {
    int u,v,w;
    scanf("%d%d%d", &u, &v, &w);
    edges[u].push_back(make_pair(make_pair(v, w), 0));
    edges[v].push_back(make_pair(make_pair(u, w), 1));
  }
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i][1] = (1LL<<61)-1;
  }
  dp[1][0] = 0;
  priority_queue<pair<ll, pair<int,int>>, vector<pair<ll, pair<int,int>>>, greater<pair<ll, pair<int,int>>>> pq;
  pq.push(make_pair(0, make_pair(1, 0)));
  while(!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    ll d = top.first;
    int u = top.second.first;
    int f = top.second.second;
    if (d > dp[u][f]) {
      continue;
    }
    for (auto p : edges[u]) {
      int v = p.first.first;
      ll w = p.first.second;
      int tp = p.second;
      if (!f) {
        if (dp[v][tp] > dp[u][f] + w) {
          dp[v][tp]= dp[u][f] + w;
          pq.push(make_pair(dp[v][tp], make_pair(v, tp)));
        }
      } else {
        if (tp && dp[v][tp] > dp[u][f] + w) {
          dp[v][tp] = dp[u][f] + w;
          pq.push(make_pair(dp[v][tp], make_pair(v, tp)));
        }
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    ll res = min(dp[i][0], dp[i][1]);
    if (res >= (1LL<<61)-1) {
      res = -1;
    }
    printf("%lld ", res);
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
