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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
vector<int> edges[N];
int dp[N][3];
int ans;
void dfs(int u, int p) {
    int mx1=-1,mx2=-1;
    int sz=0;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (v==p) continue;
        sz++;
        dfs(v, u);
        if (dp[v][1] > mx1) {
            mx2=mx1;
            mx1=dp[v][1];
        } else if (dp[v][1] > mx2) {
            mx2 = dp[v][1];
        }
    }
    if (sz == 0) {
        dp[u][0]=1;
        dp[u][1]=0;
        ans=max(ans, 1);
    } else {
        dp[u][1] = max(sz, mx1+sz-1);
        if (p!=0) ans=max(ans, dp[u][1]+1);
        else ans=max(ans, dp[u][1]);
        if (sz>=2) {
            dp[u][2] = mx1+mx2+sz-2;
            if (p!=0) ans=max(ans, dp[u][2]+1);
            else ans=max(ans, dp[u][2]);
        }
    }
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (v==p) continue;
        ans = max(ans, max(dp[v][1], dp[v][2]) + 1);
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][j] = -1;
        }
    }
    ans=0;
    dfs(1, 0);
    //if (n > 2) ans++;
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

