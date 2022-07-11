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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int b[N];
vector<int> edges[N];
int cnt[N];
int idx[N][2];
int col[N];
bool dfs(int u, int c, int& c0, int &c1) {
  if (col[u] < 0) {
    col[u] = c;
    if (c == 0) c0++;
    else c1++;
  } else {
    return col[u] == c;
  }
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (!dfs(v, !c, c0, c1)) return false;
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      cnt[i] = 0;
      edges[i].clear();
      idx[i][0] = -1;
      idx[i][1] = -1;
      col[i] = -1;
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      if (a[i] == b[i]) {
        ok=false;
      }
      cnt[a[i]]++;
      cnt[b[i]]++;
      if (idx[a[i]][0] < 0) idx[a[i]][0] = i;
      else idx[a[i]][1] = i;
      if (idx[b[i]][0] < 0) idx[b[i]][0] = i;
      else idx[b[i]][1] = i;
    }
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] != 2) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      edges[idx[i][0]].push_back(idx[i][1]);
      edges[idx[i][1]].push_back(idx[i][0]);
    }
    int tot=0;
    for (int i =1; i <= n; ++i) {
      if (col[i] < 0) {
        int c0=0;
        int c1=0;
        if (!dfs(i, 0, c0, c1)) {
          ok=false;
          break;
        }
        if (c0 != c1) {
          ok=false;
          break;
        }
      }
    }
    if (!ok) puts("NO");
    else puts("YES");
  }
  return 0;
}
