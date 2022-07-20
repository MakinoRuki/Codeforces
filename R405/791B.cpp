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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int par[N];
int deg[N];
int cnt[N];
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
//int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
    deg[i] = 0;
    cnt[i] = 1;
  }
  for (int i= 1; i <= m; ++i) {
    int a,b;
    scanf("%d%d", &a, &b);
    int pa = find(a);
    int pb = find(b);
    deg[a]++;
    deg[b]++;
    if (pa != pb) {
      par[pa] = pb;
      cnt[pb] += cnt[pa];
    }
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i) {
    int pr = find(i);
   // cout<<"i="<<i<<" "<<deg[i]<<" "<<cnt[pr]<<endl;
    if (deg[i] != cnt[pr] - 1) {
      ok=false;
      break;
    } 
  }
  if (ok) puts("YES");
  else puts("NO");
  return 0;
}
