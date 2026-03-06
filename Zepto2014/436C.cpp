/* 把关卡之间两两连边，再每个关卡到0之间连边，其实就是求生成树。 */

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
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
vector<string> mat[M];
int par[N];
vector<int> nxt[N];
bool vis[N];
void print(int cur) {
  vis[cur]=true;
  for (auto v : nxt[cur]) {
    if (!vis[v]) {
      printf("%d %d\n", v, cur);
      print(v);
    }
  }
}
int find(int u) {
  return u == par[u] ? par[u] : par[u] = find(par[u]);
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  
  cin>>n>>m>>k>>w;
  for (int p = 1; p <= k; ++p) {
    mat[p].clear();
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      mat[p].push_back(s); 
    }
  }
  vector<pair<int,pair<int,int>>> es;
  es.clear();
  for (int i = 1; i <= k; ++i) {
    es.push_back(make_pair(n*m, make_pair(0,i)));
  }
  for (int i = 1; i<=k; ++i) {
    for (int j = i+1; j <=k; ++j) {
      int cc=0;
      for (int i1=1; i1 <= n; ++i1) {
        for (int j1=1; j1 <= m; ++j1) {
          if (mat[i][i1-1][j1-1] != mat[j][i1-1][j1-1]) {
            cc++;
          }
        }
      }
      es.push_back(make_pair(cc*w, make_pair(i, j)));
    }
  }
  sort(es.begin(), es.end());
  for (int i = 0; i <= k; ++i) {
    par[i]=i;
    vis[i] = false;
    nxt[i].clear();
  }
  ll ans = 0LL;
  vector<pair<int,int>> vv;
  vv.clear();
  for (auto e : es) {
    ll z = e.first;
    int u = e.second.first;
    int v = e.second.second;
    if (u > v) swap(u, v);
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
      ans += z;
      par[pv] = pu;
   //  cout<<"uv="<<u<<" "<<v<<endl;
      nxt[u].push_back(v);
      nxt[v].push_back(u);
     // vv.push_back(make_pair(v, u));
    }
  }
  cout<<ans<<endl;
  print(0);
  // sort(vv.begin(), vv.end());
  // for (auto pr : vv) {
  //   printf("%d %d\n", pr.first, pr.second);
  // }
  return 0;
}
 
