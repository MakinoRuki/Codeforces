 
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
#define N 1000005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int c[N];
int cnt[N];
vector<int> edges[N];
ll ans;
void dfs(int u, int p) {
  if (a[u]) cnt[u]++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u);
    ans += min(cnt[v], 2*k-cnt[v]);
    cnt[u] += cnt[v];
  }
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n>>k;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= 2*k; ++i) {
    int x;
    scanf("%d", &x);
    a[x] = 1;
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  ans = 0LL;
  dfs(1, 0);
  cout<<ans<<endl;
  return 0;
}
 
