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
#define N 500005
#define M 325
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
vector<pair<int,int>> edges[N];
int ans[2*N];
int cur;
void dfs(int u, int p, int xv) {
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].second;
    if (v == p) continue;
    int id = edges[u][i].first;
    if (xv >= n) {
      ans[n+id] = n+cur;
      ans[v] = cur;
    } else {
      ans[n+id] = cur;
      ans[v] = n+cur;
    }
    cur++;
    dfs(v, u, xv ^ n);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int p;
    scanf("%d", &p);
    n = (1<<p);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(make_pair(i, v));
      edges[v].push_back(make_pair(i, u));
    }
    ans[1] = n;
    cur = 1;
    dfs(1,0, n);
    puts("1");
    for (int i = 1; i <= n; ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
    for (int i = 1; i < n; ++i) {
      printf("%d ", ans[i+n]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

