/*
一个明显的结论是，蚂蚁都往树中间的某个节点走是最好的。所以就用队列模拟，每次找出叶节点上的蚂蚁，往它的父亲节点合并，合并不了就是没解。
*/

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
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
bool vis[N];
vector<int> edges[N];
int deg[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    edges[i].clear();
    a[i]=1;
    vis[i]=false;
    deg[i]=0;
  }
  for (int i = 1; i < n; ++i) {
    int u,v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  for (int i = 1; i <= n; ++i) {
    int sz = (int)edges[i].size();
    if (sz <= 1) {
      pq.push(make_pair(a[i], i));
    }
  }
  bool ok=true;
  while(!pq.empty()) {
    auto tp = pq.top();
    pq.pop();
    int u = tp.second;
    vis[u]=true;
  //  cout<<"u="<<u<<endl;
    for (auto v : edges[u]) {
      if (vis[v]) continue;
      if (a[u] > a[v]) {
        ok=false;
        break;
      } else {
        a[v] += a[u];
        deg[v]--;
        if (deg[v] == 1) pq.push(make_pair(a[v], v));
        break;
      }
    }
    if (!ok) break;
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      ok=false;
      break;
    }
  }
  if (ok) puts("YES");
  else puts("NO");
  return 0;
}

