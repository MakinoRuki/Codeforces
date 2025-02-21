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
#define N 200005
#define M 1005
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
vector<int> edges1[M];
vector<int> edges2[M];
ll dis[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int s1,s2;
    int m1,m2;
    scanf("%d%d%d", &n, &s1, &s2);
    for (int i = 1; i <= n; ++i) {
      edges1[i].clear();
      edges2[i].clear();
    }
    scanf("%d", &m1);
    for (int i = 1; i <= m1; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges1[u].push_back(v);
      edges1[v].push_back(u);
     // cout<<"ok"<<i<<endl;
    }
    scanf("%d", &m2);
    for (int i = 1; i <= m2; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges2[u].push_back(v);
      edges2[v].push_back(u);
    }
    priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> pq;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dis[i][j] = (1LL<<61)-1;
      }
    }
    dis[s1][s2] = 0;
    pq.push(make_pair(0, make_pair(s1, s2)));
    while(!pq.empty()) {
      auto pr = pq.top();
      pq.pop();
      ll d = pr.first;
      int u1 = pr.second.first;
      int u2 = pr.second.second;
      if (d  > dis[u1][u2]) continue;
      for (int i = 0; i < edges1[u1].size(); ++i) {
        for (int j = 0; j < edges2[u2].size(); ++j) {
          int v1 = edges1[u1][i];
          int v2 = edges2[u2][j];
          if (dis[v1][v2] > dis[u1][u2] + abs(v1-v2)) {
            dis[v1][v2] = dis[u1][u2] + abs(v1-v2);
            pq.push(make_pair(dis[v1][v2], make_pair(v1, v2)));
          }
        }
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 0; j < edges1[i].size(); ++j) {
    //     cout<<"e1="<<i<<" "<<edges1[i][j]<<endl;
    //   }
    // }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 0; j < edges2[i].size(); ++j) {
    //     cout<<"e2="<<i<<" "<<edges2[i][j]<<endl;
    //   }
    // }
    ll ans=(1LL<<61)-1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < edges1[i].size(); ++j) {
        int u1 = edges1[i][j];
        //if (i==2) cout<<"sz="<<(int)edges2[i].size()<<endl;
        for (int j2 = 0; j2 < edges2[i].size(); ++j2) {
          int v1 = edges2[i][j2];
         // if (i==2) cout<<"v1="<<v1<<endl;
          if (u1 == v1) {
            //cout<<"i="<<i<<" "<<u1<<" "<<v1<<" "<<dis[i][i]<<endl;
            ans = min(ans, dis[i][i]);
          }
        }
      }
    }
    if (ans < (1LL<<61)-1) {
      printf("%lld\n", ans);
    } else {
      puts("-1");
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
