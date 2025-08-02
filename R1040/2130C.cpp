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
#define M 5002
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
vector<pair<int,int>> edges[N];
bool vis[N];
vector<int> ans;
void dfs(int u) {
    vis[u] = true;
    for (auto e : edges[u]) {
        int v = e.first;
        int id= e.second;
        if (vis[v]) continue;
        ans.push_back(id);
        dfs(v);
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; ++i) {
        edges[i].clear();
        vis[i]=false;
    }
    for (int i = 1; i <= n; ++i) {
        int x,y;
        scanf("%d%d", &x, &y);
        edges[x].push_back(make_pair(y, i));
        edges[y].push_back(make_pair(x, i));
    }
    ans.clear();
    for (int i = 1; i <= 2*n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto id : ans) {
        printf("%d ", id);
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
