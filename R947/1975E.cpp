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
#define N 300005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int par[N];
vector<int> edges[N];
int cnt[5];
set<int> ss;
int bs[N];
int fw;
int tot;
void dfs(int u, int p) {
  par[u] = p;
  int num=0;
  bs[u] = 0;
  if (!a[p] && a[u]) fw++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u);
    if (a[v]) bs[u]++;
  }
  cnt[min(3, bs[u])]++;
  if (bs[u] == 2) {
    ss.insert(u);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    tot = 0;
    ss.clear();
    bs[0] = 0;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      edges[i].clear();
      par[i] = 0;
      bs[i] = 0;
      tot += a[i];
    }
    for (int i =1; i < n; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
    cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
    fw = 0;
    dfs(1, 0);
    while(q-->0) {
      int u;
      scanf("%d", &u);
      if (a[u]) {
        cnt[min(3, bs[par[u]])]--;
        if (bs[par[u]] == 2) {
          ss.erase(par[u]);
        }
        bs[par[u]]--;
        cnt[min(3, bs[par[u]])]++;
        if (bs[par[u]] == 2) {
          ss.insert(par[u]);
        }
        fw += bs[u];
        if (!a[par[u]]) {
          fw--;
        }
        tot--;
      } else {
        cnt[min(3, bs[par[u]])]--;
        if (bs[par[u]] == 2) {
          ss.erase(par[u]);
        }
        bs[par[u]]++;
        cnt[min(3, bs[par[u]])]++;
        if (bs[par[u]] == 2) {
          ss.insert(par[u]);
        }
        fw -= bs[u];
        if (!a[par[u]]) {
          fw++;
        }
        tot++;
      }
      a[u] ^= 1;
      if (tot <= 0 || cnt[3] || cnt[2]>1) {
        puts("No");
        continue;
      }
      if (cnt[2] == 1 && a[par[*ss.begin()]]) {
        puts("No");
        continue;
      }
      if (fw > 1) {
        puts("No");
        continue;
      }
      puts("Yes");
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
 
