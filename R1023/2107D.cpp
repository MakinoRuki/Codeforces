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
#define M 1002
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
ll k;
int t;
int a[N];
vector<int> edges[N];
bool vis[N];
int par[N];
int dis[N];
vector<pair<int, pair<int,int>>> ans;
void dfs(int u, int p, int d) {
    par[u] = p;
    dis[u] = d;
    for (auto v : edges[u]) {
        if (!vis[v] && v != p) {
            dfs(v, u, d+1);
        }
    }
}
pair<int, int> solve(int u, int p) {
    par[u] = p;
    pair<int,int> res = make_pair(1, u);
    for (auto v : edges[u]) {
        if (v != p && !vis[v]) {
            auto tmp = solve(v, u);
            tmp.first += 1;
            if (tmp.first > res.first || (tmp.first==res.first && tmp.second > res.second)) {
                res = tmp;
            }
        }
    }
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
        vis[i]=false;
        par[i]=-1;
    }
    for (int i = 1; i < n; ++i) {
        int u,v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ans.clear();
    int cur=1;
    while(cur <= n) {
        if (vis[cur]) {
            cur++;
            continue;
        }
        
        // 卡常数，不要每次初始化par数组和dis数组。
        auto pr1 = solve(cur, -1);
        auto pr2 = solve(pr1.second, -1);
        int mx = max(pr1.second, pr2.second);
        int mn = min(pr1.second, pr2.second);
        ans.push_back(make_pair(-pr2.first, make_pair(-mx, -mn)));
        int u = pr1.second;
        int v = pr2.second;
        while(v > 0) {
            vis[v] = true;
            v = par[v];
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d %d ", -ans[i].first, -ans[i].second.first, -ans[i].second.second);
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
