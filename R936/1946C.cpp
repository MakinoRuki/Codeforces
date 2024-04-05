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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int dfs(int u, int p, int x, int& cnt) {
  int tot=0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    tot += dfs(v, u, x, cnt);
  }
  if (tot + 1 >= x) {
    if (p != 0) {
      cnt++;
      return 0;
    }
    return tot+1;
  } else {
    return tot+1;
  }
}
bool check(int x) {
  int cnt=0;
  int sz = dfs(1, 0, x, cnt);
  if (sz >= x) {
    if (cnt < k) return false;
    return true;
  } else {
    if (cnt < k+1) return false;
    return true;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    int l = 1, r = n;
    while(l < r) {
      int mid=(l+r+1)/2;
      if (check(mid)) {
        l = mid;
      } else {
        r=  mid-1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
