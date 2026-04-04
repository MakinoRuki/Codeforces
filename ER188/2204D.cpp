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
#define M 10002
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
// int a[N];
// int b[N];
// int c[N];
vector<int> edges[N];
int col[N];
int c0, c1;
bool ok;
void dfs(int u, int c, int p) {
 // cout<<"ucp="<<u<<" "<<c<<" "<<p<<endl;
  if (col[u] < 0) {
    col[u] = c;
    if (c==0) c0++;
    else c1++;
  } else {
    if (col[u] != c) ok=false;
    return;
  }
  
  for (auto v : edges[u]) {
    if (v == p) continue;
    dfs(v, !c, u);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
   // ll a,b,c,m;
    scanf("%d%d", &n, &m);
    for (int i =1; i <= n; ++i) {
      edges[i].clear();
      col[i]=-1;
    }
    for (int i = 1; i <= m; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      if (col[i] < 0) {
        ok=true;
        c0=0,c1=0;
        dfs(i, 0, 0);
        if (ok)
        ans += max(c0, c1);
      }
    }
    printf("%d\n", ans);
  }

  

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
