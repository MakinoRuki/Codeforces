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
#include <stack>
#define eps 1e-7
#define M 502
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
map<ll, int> idx;
vector<int> edges[N];
set<int> tes[N];
map<ll, int> col;
int col2[N];
int cnt;
ll dp[N][6];
void dfs(int u, int p) {
 // cout<<"u="<<u<<endl;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
   // cout<<"v="<<v<<endl;
    dfs(v, u);
  }
  for (int c = 0; c < 6; ++c) {
    if (col2[u] < 0 || (col2[u] == c)) {
      dp[u][c] = 1LL;
      for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (v == p) continue;
        ll tot=0LL;
        for (int j = 0; j < 6; ++j) {
          if (j / 2 != c/2) {
            tot = (tot + dp[v][j])%mod;
          }
        }
        dp[u][c] = dp[u][c] * tot % mod;
      }
    }
   // cout<<"c="<<c<<" "<<dp[u][c]<<endl;
  }
}
int getcol(string c) {
  if (c == "red") return 0;
  if (c == "orange") return 1;
  if (c == "white") return 2;
  if (c == "yellow") return 3;
  if (c == "green") return 4;
  return 5;
}
ll getpw(ll x, ll y) {
  ll res = 1LL;
  while(y) {
    if (y&1) res = res * x % mod;
    x = x*x %mod;
    y/=2;
  }
  return res;
}
int main() {
  // cin>>k;
  // vector<pair<int,string>> cs;
  // cs.clear();
  // for (int i = 1; i < (1<<k); ++i) {
  //   int x = rand()%2;
  //   if (x == 1) {
  //     int cc = rand()%6;
  //     if (cc == 0) cs.push_back(make_pair(i, "red"));
  //     else if (cc == 1) cs.push_back(make_pair(i, "orange"));
  //     else if (cc == 2) cs.push_back(make_pair(i, "white"));
  //     else if (cc == 3) cs.push_back(make_pair(i, "yellow"));
  //     else if (cc == 4) cs.push_back(make_pair(i, "green"));
  //     else cs.push_back(make_pair(i, "blue"));
  //   }
  // }
  // cout<<min(2000, (int)cs.size())<<endl;
  // for (int i = 0; i < min(2000, (int)cs.size()); ++i) {
  //   printf("%d ", cs[i].first);
  //   cout<<cs[i].second<<endl;
  // }
  cin>>k>>n;
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    ll id;
    string c;
    scanf("%lld", &id);
    cin>>c;
    col[id] = getcol(c);
  }
  memset(col2, -1, sizeof(col2));
  for (auto itr : col) {
    ll v = itr.first;
    while(v >= 1) {
      if (idx.find(v) == idx.end()) {
        idx[v] = ++cnt;
      }
      int id = idx[v];
      if (col.find(v) != col.end()) {
        col2[id] = col[v];
      }
      ll v2 = v/2;
      if (v2 >= 1) {
        if (idx.find(v2) == idx.end()) {
          idx[v2] = ++cnt;
        }
        int id2 = idx[v2];
        tes[id2].insert(id);
      }
      v = v2;
    }
  }
  for (int i = 1; i <= cnt; ++i) {
    for (auto itr : tes[i]) {
      edges[i].push_back(itr);
    }
  }
  memset(dp, 0LL, sizeof(dp));
  dfs(idx[1], 0);
  ll ans = 0LL;
  if (col.find(1) != col.end()) {
    ans = dp[idx[1]][col[1]];
   // cout<<"dp="<<dp[idx[1]][col[1]]<<endl;
  } else {
    for (int i = 0; i < 6; ++i) {
      ans= (ans + dp[idx[1]][i]) % mod;
    }
  }
 // cout<<ans<<endl;
  ll m = (1LL<<k)-1-(ll)cnt;
 // if (k==45) cout<<ans<<endl;
  ans = ans * getpw(4LL, m) % mod;
  cout<<ans<<endl;
  return 0;
}
