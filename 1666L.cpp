/*因为每次从s出发，每条符合条件的路径应该是s的一个不同的儿子，因此它们所在的dfs树是不同的。因此直接dfs就好。要么找到解，要么dfs遍历所有节点。*/


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
int s;
int a[N];
vector<int> edges[N];
int par[N];
int id[N];
int id0,id1;
void dfs(int u, int tag, int p) {
  par[u] = p;
  id[u] = tag;
  for (auto v : edges[u]) {
    // 注意需要不看s。
    if (v == s) continue;
    if (id[v] < 0) {
      dfs(v, tag, u);
      if (t >= 0) return;
    } else {
      if (id[v] != tag) {
        t = v;
        id0 = par[v];
        id1 = u;
        break;
      }
    }
  }
}
void calc(int u) {
  vector<int> vv;
  vv.clear();
  while(u != s) {
    vv.push_back(u);
    u = par[u];
  }
  vv.push_back(s);
  printf("%d\n", (int)vv.size()+1);
  for (int i = vv.size()-1; i >= 0; --i) {
    printf("%d ", vv[i]);
  }
  cout<<t<<endl;
}
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>n>>m>>s;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
  }
  memset(id, -1, sizeof(id));
  t = -1;
  for (int i = 0; i < edges[s].size(); ++i) {
    int u = edges[s][i];
   // 考虑直接连接的边。
    if (id[u] >= 0) {
      t = u;
      id0 = par[u];
      id1 = s;
    } else {
      dfs(u, i, s);
    }
    if (t > 0) {
      break;
    }
    // for (int x=1; x<=n; ++x) {
    //   cout<<"i="<<i<<" "<<id[i]<<endl;
    // }
  }
  if (t < 0) {
    puts("Impossible");
  } else {
    puts("Possible");
    calc(id0);
    calc(id1);
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
