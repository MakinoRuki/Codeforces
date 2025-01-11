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
int n, m, q;
int k;
int t;
vector<pair<int,ll>> edges[N];
ll sum[2][N];
int a,b;
void dfs(int u, int id, int p, ll cur) {
    sum[id][u] = cur;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i].first;
        ll w = edges[u][i].second;
        if (v == p) continue;
        if ((id == 0) && (v == b) && ((cur^w)!=0)) continue;
        dfs(v, id, u, cur^w);
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        edges[u].push_back(make_pair(v,w));
        edges[v].push_back(make_pair(u, w));
    }
    for (int i = 0; i <= n; ++i) {
        sum[0][i]=sum[1][i]=-1;
    }
    ll cur=0;
    dfs(a, 0, 0, cur);
    cur=0;
    dfs(b, 1, 0, cur);
    if (sum[0][b] == 0) {
        puts("YES");
    } else {
        bool found=false;
        set<ll> ss;
        ss.clear();
        for (int i = 1; i <= n; ++i) {
            if (i==b) continue;
            ss.insert(sum[0][i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (i==b) continue;
            if (ss.find(sum[1][i])!=ss.end()) {
                found=true;
                break;
            }
        }
        if (found) puts("YES");
        else puts("NO");
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
