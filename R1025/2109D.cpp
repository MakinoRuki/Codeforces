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
#define M 1002
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
ll k;
int t;
int a[N];
int dis[N][2];
vector<int> edges[N];
void spfa() {
  priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
  for (int i = 1; i <= n; ++i) {
    dis[i][0] = inf;
    dis[i][1] = inf;
  }
  dis[1][0] = 0;
  dis[1][1] = inf;
  pq.push(make_pair(dis[1][0], make_pair(1, 0)));
  while(!pq.empty()) {
    auto pr = pq.top();
    pq.pop();
    int d = pr.first;
    int u = pr.second.first;
    int p = pr.second.second;
    if (d > dis[u][p]) {
      continue;
    }
    for (auto v : edges[u]) {
      if (dis[v][!p] > dis[u][p] + 1) {
        dis[v][!p] = dis[u][p] + 1;
        pq.push(make_pair(dis[v][!p], make_pair(v, !p)));
      }
    }
  }
}
bool check(int u, int pr, ll tot, int mn) {
  if (dis[u][pr] >= inf) return false;
  if ((tot%2) == pr) {
    if (tot >= dis[u][pr]) {
      return true;
    }
    return false;
  } else {
    if (mn >= inf) {
      return false;
    }
    if (tot - mn >= dis[u][pr]) {
      return true;
    }
    return false;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &q);
    ll tot=0LL;
    int mn=inf;
    for (int i = 1; i <= q; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
      if (a[i]%2) mn=min(mn, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      dis[i][0]=inf;
      dis[i][1]=inf;
    }
    for (int i = 1; i <= m; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    spfa();
    string ans="1";
    for (int i = 2; i <= n; ++i) {
      if (check(i, 0, tot, mn)) {
        ans.push_back('1');
      } else if (check(i, 1, tot, mn)) {
        ans.push_back('1');
      } else {
        ans.push_back('0');
      }
    }
    cout<<ans<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
