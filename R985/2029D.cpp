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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
int a[N];
set<int> es[N];
int deg[N];
bool vis[N];
vector<pair<int,pair<int,int>>> ans;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      deg[i] = 0;
      es[i].clear();
      vis[i]=false;
    }
    for (int i = 1; i <= m; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      deg[u]++;
      deg[v]++;
      es[u].insert(v);
      es[v].insert(u);
    }
    ans.clear();
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (deg[i]>1) {
        q.push(i);
        vis[i]=true;
      }
    }
    while(!q.empty()) {
      auto u = q.front();
      q.pop();
      vis[u]=false;
      vector<int> v(es[u].begin(), es[u].end());
      int sz=(int)v.size();
      for (int i = 1; i <= sz/2*2; i+=2) {
        int v1 = v[i-1];
        int v2 = v[i];
        ans.push_back(make_pair(u, make_pair(v1,v2)));
        es[u].erase(v1);
        es[v1].erase(u);
        es[u].erase(v2);
        es[v2].erase(u);
        deg[u] -= 2;
        deg[v1]--;
        deg[v2]--;
        if (es[v1].find(v2) != es[v1].end()) {
          es[v1].erase(v2);
          es[v2].erase(v1);
          deg[v1]--;
          deg[v2]--;
        } else {
          es[v1].insert(v2);
          es[v2].insert(v1);
          deg[v1]++;
          deg[v2]++;
        }
        if (deg[v1]>1 && !vis[v1]) {
          q.push(v1);
          vis[v1]=true;
        }
        if (deg[v2]>1 && !vis[v2]) {
          q.push(v2);
          vis[v2]=true;
        }
      }
    }
    int u1=0,u2=0;
    for (int i = 1; i <= n; ++i) {
      if (deg[i]>0) {
        u1 = i;
        u2 = *es[i].begin();
        break;
      }
    }
    if (u1) {
      for (int i = 1; i <= n; ++i) {
        vis[i]=false;
      }
      vis[u1]=true;
      vis[u2]=true;
      for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (deg[i] == 0) {
          ans.push_back(make_pair(u1, make_pair(u2, i)));
          u2 = i;
          vis[i]=true;
        } else {
          int v1 = *es[i].begin();
          ans.push_back(make_pair(u1, make_pair(i, v1)));
          vis[i]=true;
          vis[v1]=true;
        }
      }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

