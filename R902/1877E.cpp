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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int nxt[N];
int deg[N];
bool vis[N];
int col[N];
bool check(int u, int cc, vector<int>& vv) {
  int v=nxt[u];
  cc=!cc;
  while(v != u) {
    if (col[v] >= 0 && col[v]!=cc) {
      return false;
    }
    col[v] = cc;
    v=nxt[v];
    cc=!cc;
  }
  col[v]=cc;
  return true;
}
int main() {
  cin>>n;
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    nxt[i]=a[i];
    deg[a[i]]++;
    vis[i]=false;
    col[i]=-1;
  }
  bool ok=true;
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if (col[u]==1 || col[nxt[u]]==0) {
      ok=false;
      break;
    }
    col[u]=0;
    if (col[nxt[u]]==1) continue;


    col[nxt[u]]=1;
    vis[u]=true;
    vis[nxt[u]]=true;
    deg[nxt[nxt[u]]]--;
    if (deg[nxt[nxt[u]]] == 0) {
      q.push(nxt[nxt[u]]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      col[i]=0;
      deg[i]=0;
      q.push(i);
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (col[u]==1 || col[nxt[u]]==0) {
          ok=false;
          break;
        }
        col[u]=0;
        if (col[nxt[u]]==1) continue;

        
        col[nxt[u]]=1;
        vis[u]=true;
        vis[nxt[u]]=true;
        deg[nxt[nxt[u]]]--;
        if (deg[nxt[nxt[u]]] == 0) {
          q.push(nxt[nxt[u]]);
        }
      }
    }
    if (!ok)break;
  }
  if (!ok) puts("-1");
  else {
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      if (col[i]==0) ans.push_back(a[i]);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
