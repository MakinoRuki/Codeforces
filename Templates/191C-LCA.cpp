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
#define N 100005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
vector<pair<int, int>> edges[N];
int id1[N];
int id2[5*N];
int dep[5*N];
int dp[5*N][30];
int cnt;
int num[N];
int ans[N];
void dfs1(int u, int p, int d) {
  ++cnt;
  id1[u] = cnt;
  dep[cnt] = d;
  id2[cnt] = u;
  dp[cnt][0] = cnt;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    if (v!=p) {
      dfs1(v, u, d+1);
      ++cnt;
      id2[cnt] = u;
      dep[cnt] = d;
      dp[cnt][0] = cnt;
    }
  }
}
int getlca(int u, int v) {
  int x = id1[u];
  int y = id1[v];
  if (x > y) swap(x, y);
  int len = y-x+1;
  int pw;
  for (pw = 0; (1<<pw) <= len; ++pw) {

  }
  pw--;
  // if (u == 3 && v == 5) {
  //   cout<<":"<<x<<" "<<y<<" "<<pw<<endl;
  // }
  int x2 = dp[x][pw];
  int y2 = dp[y-(1<<pw)+1][pw];
  // if (u==3 && v==5) {
  //   cout<<"??"<<x2<<" "<<y2<<endl;
  // }
  if (dep[x2] < dep[y2]) {
    return id2[x2];
  } else {
    return id2[y2];
  }
}
void dfs2(int u, int p) {
  for (int i = 0; i <edges[u].size(); ++i) {
    int v = edges[u][i].first;
    int id = edges[u][i].second;
    if (v != p) {
      dfs2(v, u);
      ans[id] += num[v];
      num[u] += num[v];
    }
  }
}
int main() {
  cin>>n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(make_pair(v, i));
    edges[v].push_back(make_pair(u, i));
  }
  cnt=0;
  memset(id1, -1, sizeof(id1));
  memset(id2, -1, sizeof(id2));
  memset(dp, -1, sizeof(dp));
  dfs1(1, 0, 0);
  // for (int i = 1; i <= n; ++i) {
  //   cout<<"id1="<<i<<" "<<id1[i]<<endl;
  // }
  // for (int i =1; i <= cnt; ++i) {
  //   cout<<"id2="<<i<<" "<<id2[i]<<endl;
  // }
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= cnt; ++j) {
      if (j+(1<<i)-1 <= cnt) {
        int x = dp[j][i-1];
        if (x >= 0) {
          int y = dp[j+(1<<(i-1))][i-1];
          //if (i==1 && j==1) cout<<"!!"<<x<<" "<<y<<endl;
          if (y < 0) continue;
          if (dep[x] < dep[y]) {
            dp[j][i] = x;
          } else {
            dp[j][i] = y;
          }
        }
      }
    }
  }
  //cout<<"dp="<<dp[1][1]<<endl;
  cin>>k;
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= k; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    num[a]++;
    num[b]++;
    //cout<<"lca="<<getlca(a,b)<<endl;
    num[getlca(a,b)] -= 2;
  }
  memset(ans, 0, sizeof(ans));
  dfs2(1, 0);
  for (int i = 1; i < n; ++i) {
    printf("%d", ans[i]);
    if (i < n-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
