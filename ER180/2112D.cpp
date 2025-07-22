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
int k;
int t;
int a[N];
int b[N];
vector<pair<int,int>> edges[N];
int ans[N];
vector<pair<int,int>> es;
void dfs(int u, int p, int d) {
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i].first;
        int id = edges[u][i].second;
        if (v==p) continue;
        ans[id] = d;
        if (d == 0) {
            if (es[id-1].first != v) {
                swap(es[id-1].first, es[id-1].second);
            }
        } else {
            if (es[id-1].first != u) {
                swap(es[id-1].first, es[id-1].second);
            }
        }
        dfs(v, u, !d);
    }
}
void dfs2(int u, int p) {
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i].first;
        int id = edges[u][i].second;
        if (p == v) continue;
        ans[id] = !ans[id];
        swap(es[id-1].first, es[id-1].second);
        dfs2(v, u);
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
    }
    es.clear();
    for (int i =1; i < n; ++i) {
        int u,v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(make_pair(v, i));
        edges[v].push_back(make_pair(u, i));
        es.push_back(make_pair(u, v));
    }
    dfs(1, 0, 0);
   // cout<<"??"<<endl;
    // for (auto pr : es) {
    //     cout<<"vv="<<pr.first<<" "<<pr.second<<endl;
    // }
    int v = 0;
    for (int i = 1; i <= n; ++i) {
        int sz=(int)edges[i].size();
        if (sz == 2) {
            v = i;
            break;
        }
    }
    if (v <= 0) {
        puts("No");
        continue;
    }
    int id = edges[v][0].second;
    ans[id] = !ans[id];
    swap(es[id-1].first, es[id-1].second);
   // cout<<"???"<<endl;
  //  cout<<"???"<<id<<" "<<v<<" "<<edges[v][0].first<<endl;
    dfs2(edges[v][0].first, v);
    
    puts("Yes");
    for (int i = 1; i < n; ++i) {
        printf("%d %d\n", es[i-1].first, es[i-1].second);
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
