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
#define N 600005
#define M 750
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
int a[N];
vector<int> edges[N];
int dep[N];
int mark[N];
vector<int> vs;
int st,ed;
void dfs(int u, int p, int d) {
    dep[u] = d;
    if (u == ed) {
        mark[u] = 1;
        vs.push_back(u);
    }
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (v == p) continue;
        dfs(v, u, d+1);
        if (mark[v]) {
            mark[u]=1;
            vs.push_back(u);
        }
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &st, &ed);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
        dep[i]=0;
        mark[i]=0;
    }
    for (int i = 1; i < n; ++i) {
        int u,v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vs.clear();
    dfs(st, 0, 0);
    vector<int> ans;
    ans.clear();
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
        if (!mark[i]) {
            rk.push_back(make_pair(dep[i], i));
        }
    }
    sort(rk.begin(), rk.end());
    for (int i = (int)rk.size()-1; i >= 0; --i) {
        ans.push_back(rk[i].second);
    }
    for (int i = (int)vs.size()-1; i >= 0; --i) {
        ans.push_back(vs[i]);
    }
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
