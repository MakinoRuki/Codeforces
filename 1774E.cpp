/*
如果没有距离不超过d的限制，那么两条访问路径是独立的。现在如果考虑d的话，因为有必须要回到1的条件，也就是说a中每个顶点的距离为d的父节点必在b中，而b中每个顶点距离为d的父节点也必在a中。
修改过a和b之后，分别独立计算再加起来。
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
#define N 200005
#define M 1005
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
int b[N];
vector<int> edges[N];
int dp[N][20];
int par[N];
ll dt;
bool vis1[N];
bool vis2[N];
int dfs2(int u, int p) {
  int vv=0;
  if (vis1[u]) vv |= 1;
  if (vis2[u]) vv |= 2;
  for (auto v : edges[u]) {
    if (v == p) continue;
    int res=dfs2(v, u);
 //   cout<<"uv="<<u<<" "<<v<<" "<<res<<endl;
    if (res) {
      if (res==1 || res==2) dt += 2;
      else dt += 4;
    }
    vv |= res;
  }
  return vv;
}
ll calc(set<int>& s1, set<int>& s2) {
  for (int i =1; i <= n; ++i) {
    vis1[i]=false;
    vis2[i]=false;
    if (s1.find(i) != s1.end()) vis1[i]=true;
    if (s2.find(i) != s2.end()) vis2[i]=true;
  }
  dt=0;
  dfs2(1, 0);
  return dt;
}
void dfs(int u, int p) {
  dp[u][0] = p;
//  if (u==4) cout<<"???"<<dp[u][0]<<endl;
  for (auto v : edges[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}
int getfa(int u, int dd) {
  for (int i = 20; i >= 0; --i) {
    if ((1<<i) <= dd) {
      u = dp[u][i];
      dd -= (1<<i);
    }
  }
  if (dd) u = dp[u][0];
  return u;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  int d;
  cin>>n>>d;
  for (int i =1; i < n; ++i) {
    int u,v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 0; i < 20; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[j][i]=0;
    }
  }
  dfs(1, 0);
//  cout<<"vvv="<<dp[4][0]<<endl;
  for (int i = 1; i < 20; ++i) {
    for (int j = 1; j <= n; ++j) {
      int pp = dp[j][i-1];
      if (pp > 0 && dp[pp][i-1]) {
        dp[j][i] = dp[pp][i-1];
      }
    }
  }
//  cout<<"vv="<<dp[4][0]<<" "<<dp[4][1]<<" "<<dp[4][2]<<endl;
  set<int> s1, s2;
  s1.clear();
  s2.clear();
  int m1,m2;
  scanf("%d", &m1);
  for (int i = 1; i <= m1; ++i) {
    scanf("%d", &a[i]);
    s1.insert(a[i]);
    int pa = getfa(a[i], d);
  //  cout<<"pa="<<a[i]<<" "<<pa<<endl;
    s2.insert(pa);
  }
  scanf("%d", &m2);
  for (int i = 1; i <= m2; ++i) {
    scanf("%d", &b[i]);
    s2.insert(b[i]);
    int pa = getfa(b[i], d);
    s1.insert(pa);
  }
  ll ans=0LL;
  ans += calc(s1, s2);
  cout<<ans<<endl;
  return 0;
}
