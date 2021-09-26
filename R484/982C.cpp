#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 12
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<int> edges[N];
int ans;
int dfs(int u, int p) {
  int cnt=1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) {
      continue;
    }
    cnt += dfs(v, u);
  }
  if (cnt % 2 == 0) {
    if (u != 1) ans++;
    return 0;
  }
  return 1;
}
int main() {
  cin>>n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  if (n % 2) {
    puts("-1");
    return 0;
  }
  ans = 0;
  dfs(1, 0);
  cout<<ans<<endl;
  return 0;
}
