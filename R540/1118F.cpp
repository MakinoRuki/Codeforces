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
#define M 202
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<int> edges[N];
int cnt[N][2];
int c1,c2;
void dfs(int u, int p, int& ans) {
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, ans);
    if ((cnt[v][0] == c1 && cnt[v][1]==0) || (cnt[v][1] == c2 && cnt[v][0]==0)) {
      ans++;
    }
    cnt[u][0] += cnt[v][0];
    cnt[u][1] += cnt[v][1];
  }
  if (a[u] == 1) cnt[u][0]++;
  else if (a[u] == 2) cnt[u][1]++;
}
int main() {
  cin>>n;
  c1 = 0, c2=0;
  for (int i=1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 1) c1++;
    else if (a[i] == 2) c2++;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(cnt, 0, sizeof(cnt));
  int ans=0;
  dfs(1, 0, ans);
  cout<<ans<<endl;
  return 0;
}
