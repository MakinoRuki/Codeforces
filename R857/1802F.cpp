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
#define N 803
#define M 505
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
int w[N];
ll p;
vector<pair<int,int>> edges[N];
ll dp[N][N][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%lld", &n, &m, &p);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &w[i]);
      edges[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int x,y,z;
      scanf("%d%d%d", &x, &y, &z);
      edges[x].push_back(make_pair(y, z));
    }
    for (int i =1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = (1LL<<61)-1;
        }
      }
    }
    priority_queue<pair<pair<ll,ll>,pair<int,int>>, vector<pair<pair<ll,ll>,pair<int,int>>>, greater<pair<pair<ll,ll>,pair<int,int>>>> pq;
    dp[1][1][0] = 0;
    dp[1][1][1] = p;
    pq.push(make_pair(make_pair(0, -p), make_pair(1, 1)));
    while(!pq.empty()) {
      auto tp = pq.top();
      pq.pop();
      ll cnt = tp.first.first;
      ll res = -tp.first.second;
      int u = tp.second.first;
      int uu = tp.second.second;
      if (cnt > dp[u][uu][0] || (cnt == dp[u][uu][0] && res < dp[u][uu][1])) {
        continue;
      }
      for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i].first;
        ll tmp = edges[u][i].second;
        ll ncnt = cnt;
        ll nres = res;
        if (res >= tmp) {
          nres -= tmp;
        } else {
          ll dt = tmp - res;
          ll r = (dt+w[uu]-1)/w[uu];
          ncnt += r;
          nres = nres + r * w[uu] - tmp;
        }
        int nuu = uu;
        if (w[v] > w[nuu]) {
          nuu = v;
        }
        if (dp[v][nuu][0] > ncnt || (dp[v][nuu][0] == ncnt && dp[v][nuu][1] < nres)) {
          pq.push(make_pair(make_pair(ncnt, -nres), make_pair(v, nuu)));
          dp[v][nuu][0] = ncnt;
          dp[v][nuu][1] = nres;
        }
      }
    }
    ll ans = (1LL<<61)-1;
    for (int i = 1; i <= n; ++i) {
      if (dp[n][i][0] < ans) {
        ans = dp[n][i][0];
      }
    }
    if (ans < (1LL<<61)-1) {
      printf("%lld\n", ans);
    } else {
      puts("-1");
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
