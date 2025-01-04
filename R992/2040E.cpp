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
#define N 300005
#define M 2010
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
int cnt[N];
int par[N];
void dfs(int u, int p) {
    par[u]=p;
    cnt[u] = 0;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v= edges[u][i];
        if (v==p) continue;
        dfs(v, u);
        cnt[u]++;
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u,v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0);
    while(q-->0) {
        int v;
        scanf("%d%d", &v, &m);
        vector<int> vv;
        vv.clear();
        int u = v;
        ll ans=0;
        int num=0;
        while(u != 1) {
           // cout<<"u="<<u<<endl;
            num++;
            if ((num%2)==0) vv.push_back(cnt[u]);
            u = par[u];
            ans++;
        }
        sort(vv.begin(), vv.end());
        for (int i = vv.size()-1; i >= 0; --i) {
            if ((int)vv.size()-i <= m) {
                continue;
            }
            ans += 2LL*vv[i];
        }
        printf("%lld\n", ans);
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
