
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
vector<int> edges[N];
int dfn[N];
int low[N];
int ts;
int stk[N];
vector<vector<int>> cs;
int cnt;
int top;
int col[N];
int odd[N];
int id[N];
void dfs(int u, int c) {
  col[u] = c;
  for (auto v : edges[u]) {
    if (col[v] < 0 && (id[v] == id[u])) {
      dfs(v, !c);
    }
  }
}
void tarjan(int u, int p) {
  dfn[u] = low[u] = ++ ts;
  stk[++ top] = u;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    }
    else low[u] = min(low[u], dfn[v]);
  }
  
  if (low[u] == dfn[u]) {
    int temp = 0;
    cnt ++, cs.push_back(vector<int>());
    do { 
      temp = stk[top --];
      id[temp] = cnt;
      cs.back().push_back(temp);
    } while (temp != u);
  }
}
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      edges[i].clear();
      col[i]=-1;
      dfn[i] = low[i]=0;
    }
    for (int i = 1; i <= m; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    ts=0;
    cnt=0;top=-1;
    cs.clear();
    tarjan(1, 0);
    for (auto v : cs) {
      dfs(v[0], 0);
      // for (auto i : v) {
      //   cout<<i<<" ";
      // }
      // cout<<endl;
    }
    for (int i = 1; i <= cnt; ++i) {
      odd[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      for (auto v : edges[i]) {
        if (id[v] == id[i]) {
          if (col[v] == col[i]) {
          //  cout<<"iv="<<v<<" "<<i<<" "<<endl;
            odd[id[i]] = true;
          }
        }
      }
    }
    // for (int i = 1; i <= cnt; ++i) {
    //   cout<<"i="<<i<<" "<<odd[i]<<endl;
    // }
    ll ans=1LL;
    for (auto v : cs) {
      set<int> ss;
      ss.clear();
      for (auto u : v) {
        if (a[u] != -1) ss.insert(a[u]);
      }
      int sz=(int)ss.size();
      if (sz > 1) {
        ans=0LL;
        break;
      }
      int num=id[v[0]];
      if (sz == 1) {
        auto cc = *ss.begin();
        if (odd[num]) {
          if (cc != 0) {
            ans=0LL;
            break;
          }
        }
      } else {
        if (!odd[num]) ans = ans * (ll)k % mod2;
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
