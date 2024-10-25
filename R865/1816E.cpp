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
int dis[N];
vector<int> edges[N];
vector<int> ss[N];
bool vis[N];
void bfs() {
  for (int i = 1; i <= n; ++i) {
    dis[i] = inf;
    vis[i] = false;
  }
  dis[1] = 1;
  vis[1] = true;
  queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u]+1;
        q.push(v);
        vis[v] = true;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (dis[i] < inf){
      ss[dis[i]].push_back(i);
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      ss[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      edges[y].push_back(x);
    }
    bfs();
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      if (dis[i] == inf) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("INFINITE");
      continue;
    }
    vector<int> ans;
    ans.clear();
    int mx=1;
    for (int i = 1; i <= n; ++i) {
      mx = max(mx, dis[i]);
    }
    for (int i = mx; i >= 1; --i) {
      for (int j = mx; j >= mx-i+1; --j) {
        for (auto itr : ss[j]) {
          ans.push_back(itr);
        }
      }
    }
    puts("FINITE");
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
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

