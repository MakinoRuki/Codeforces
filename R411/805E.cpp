#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
vector<int> cs[N];
vector<int> edges[N];
int ans[N];
int cnt;
void dfs(int u, int p) {
  
  set<int> ss;
  ss.clear();
  vector<int> tmp;
  tmp.clear();
  for (int i = 0; i < cs[u].size(); ++i) {
    int c = cs[u][i];
    if (ans[c] >= 1) {
      ss.insert(ans[c]);
    } else {
      tmp.push_back(c);
    }
  }
  int cur=1;
  for (int i = 0; i < tmp.size(); ++i) {
    int c = tmp[i];
    while(ss.find(cur) != ss.end()) {
      cur++;
    }
    if (cur > cnt) {
      cnt++;
    }
    ans[c] = cur;
    ss.insert(cur);
    //cnt = max(cnt, cur);
  }
  // Need to from top to bottom, for example : 
  /* 3 2
     2 1 2
     1 1
     1 2
     1 2
     1 3 */
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u);
  }
}
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      int x;
      scanf("%d", &x);
      cs[i].push_back(x);
    }
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(ans, -1, sizeof(ans));
  cnt = 0;
  dfs(1, 0);
  for (int i = 1; i <= m; ++i) {
    if (ans[i] < 0) {
      ans[i] = 1;
      cnt=max(cnt, 1);
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= m; ++i) {
    printf("%d", ans[i]);
    if (i < m) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
