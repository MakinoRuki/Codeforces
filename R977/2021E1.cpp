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
int a[M];
int dis[M][M];
int res[M];
bool vis[M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= p; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i==j) dis[i][j]=0;
        else dis[i][j]=inf;
      }
    }
    for (int i = 1; i <= m; ++i) {
      int u,v,w;
      scanf("%d%d%d", &u, &v, &w);
      dis[u][v] = dis[v][u] = w;
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
        }
      }
    }
   // cout<<dis[1][2]<<" "<<dis[2][3]<<" "<<dis[1][3]<<endl;
    for (int i = 1; i <= n; ++i) {
      res[i]=-1;
      vis[i]=false;
    }
    ll ans = (1LL<<61)-1;
    for (int k = 1; k <= n; ++k) {
      ll tmp=ans;
      int id=0;
      for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        ll tot=0LL;
        for (int j = 1; j <= p; ++j) {
          int v= a[j];
          if (res[v]<0) tot += dis[i][v];
          else tot += min(dis[i][v], dis[res[v]][v]);
        }
        if (tot <= tmp) {
          tmp = tot;
          id = i;
        }
      }
      vis[id] = true;
      ans = 0LL;
      for (int i = 1; i <= p; ++i) {
        int v= a[i];
        if (res[v] < 0) res[v] =id;
        else if (dis[id][v] < dis[res[v]][v]) {
          res[v]= id;
        }
        ans += dis[v][res[v]];
      }
      //cout<<"k="<<k<<" "<<id<<" "<<dis[1][id]<<" "<<dis[2][id]<<" "<<dis[3][id]<<endl;
      printf("%lld ", ans);
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

