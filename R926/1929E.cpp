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
#define N 2000005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
vector<pair<int,int>> edges[N];
vector<pair<int,int>> es;
int st[N];
int dp[N];
bool dfs(int u, int p, int tt, int cnt) {
  if (u == tt) {
    return true;
  }
  for (int i = 0; i < edges[u].size(); ++i) {
    int v  = edges[u][i].first;
    int id = edges[u][i].second;
    if (v == p) continue;
    if (dfs(v, u, tt, cnt)) {
      st[id] |= (1<<cnt);
      return true;
    }
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      st[i]=0;
    }
    es.clear();
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(make_pair(v,i));
      edges[v].push_back(make_pair(u,i));
      es.push_back(make_pair(u,v));
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      dfs(x, 0, y, i-1);
    }
    set<int> ss;
    ss.clear();
    for (int i = 1; i < n; ++i) {
      //cout<<"i="<<i<<" "<<st[i]<<endl;
      ss.insert(st[i]);
    }
    vector<int> v(ss.begin(), ss.end());
    for (int i = 0; i < (1<<k); ++i) {
      dp[i] = inf;
    }
    dp[0] = 0;
    for (int s = 0; s < (1<<k); ++s) {
      if (dp[s]>=inf)continue;
      for (auto i : v) {
        int s2 = s|i;
        if (s2 > s) {
          dp[s2] = min(dp[s2], dp[s]+1);
        }
      }
    }
    printf("%d\n", dp[(1<<k)-1]);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

