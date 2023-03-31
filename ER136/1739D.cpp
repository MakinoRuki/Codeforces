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
#define N 200005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
vector<int> edges[N];
int dep[N];
int cnt;
void dfs(int u, int p, int d) {
  dep[u] = d;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}
int dfs2(int u, int p, int d) {
  int mx = -1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    mx = max(mx, dfs2(v, u, d));
  }
  //if (d == 1) cout<<"u="<<u<<" "<<mx<<endl;
  if (u != 1 && mx + 1 >= d-1 && p != 1) {
    cnt++;
    return -1;
  }
  return mx+1;
}
bool check(int d) {
  cnt = 0;
  dfs2(1, 0, d);
  return cnt <= k;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
      int p;
      scanf("%d", &p);
      edges[p].push_back(i);
    }
    dfs(1, 0, 0);
    int l = 1, r = n-1;
    while(l < r) {
      int mid = (l +r)/2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
