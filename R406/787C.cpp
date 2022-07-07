#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 7005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
//int a[N];
int dp[N][2];
int deg[N][2];
vector<int> os[2];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>n;
  for (int i = 0; i < 2; ++i) {
    scanf("%d", &k);
    os[i].clear();
    for (int j = 1; j <= k; ++j) {
      int x;
      scanf("%d", &x);
      os[i].push_back(x);
    }
  }
  memset(deg,0,sizeof(deg));
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  dp[0][1] = 0;
  queue<pair<int,int>> q;
  q.push(make_pair(0, 0));
  q.push(make_pair(0, 1));
  while(!q.empty()) {
    auto pr = q.front();
    q.pop();
    int u = pr.first;
    int p = pr.second;
    if (dp[u][p]) {
      for (int i = 0; i < os[!p].size(); ++i) {
        int d = os[!p][i];
        int v = (u - d + n) % n;
        if (dp[v][!p] < 0) {
          deg[v][!p]++;
          if (deg[v][!p] == os[!p].size()) {
            dp[v][!p] = 0;
            q.push(make_pair(v, !p));
          }
        }
      }
    } else {
      for (int i = 0; i < os[!p].size(); ++i) {
        int d = os[!p][i];
        int v = (u - d + n) % n;
        if (dp[v][!p] < 0) {
          dp[v][!p] = 1;
          q.push(make_pair(v, !p));
        }
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (dp[i-1][0] == 1) {
      cout<<"Win";
    } else if (dp[i-1][0] == 0) {
      cout<<"Lose";
    } else {
      cout<<"Loop";
    }
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  for (int i = 2; i <= n; ++i) {
    if (dp[i-1][1] == 1) {
      cout<<"Win";
    } else if (dp[i-1][1] == 0) {
      cout<<"Lose";
    } else {
      cout<<"Loop";
    }
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
