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
int id1[N];
int id2[N];
int cnt;
void dfs(int u, int p) {
  ++cnt;
  id1[u]=cnt;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v=edges[u][i];
    if (v==p) continue;
    dfs(v, u);
  }
  id2[u]=cnt;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    cnt=0;
    dfs(1, 0);
    map<int, vector<int>> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      mp[-a[i]].push_back(i);
    }
    int pre=0;
    int ans=0;
    int mx=0,mn=0;
    for (auto itr : mp) {
      int w = itr.first;
      auto v = itr.second;
      for (int i = 0; i < v.size(); ++i) {
        int id = v[i];
        if (pre != 0) {
          if (mn < id1[id] || mx > id2[id]) {
            ans=id;
            break;
          }
        }
      }
      if (ans>0) break;
      pre=w;
      for (int i = 0; i < v.size(); ++i) {
        if (i==0) mn=id1[v[i]],mx=id2[v[i]];
        else mn=min(mn,id1[v[i]]),mx=max(mx,id2[v[i]]);
      }
    }
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
