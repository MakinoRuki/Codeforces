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
#include <stack>
#define eps 1e-7
#define M 502
#define N 500002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
vector<pair<int,int>> edges[N];
int res[N];
bool dfs(int u, int c, int& cnt, vector<int>& ids) {
  if (res[u] >= 0) {
    if (res[u] != c) return false;
    return true;
  }
  ids.push_back(u);
  res[u] = c;
  if (c == 1) cnt++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    int cc = edges[u][i].second;
    if (!dfs(v, c ^ cc, cnt, ids)) return false;
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      res[i] = -1;
      edges[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      string s;
      scanf("%d%d", &u, &v);
      cin>>s;
      if (s[0] == 'c') {
        edges[u].push_back(make_pair(v, 0));
        edges[v].push_back(make_pair(u, 0));
      } else {
        edges[u].push_back(make_pair(v, 1));
        edges[v].push_back(make_pair(u, 1));
      }
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      if (res[i] < 0) {
        vector<int> ids;
        ids.clear();
        int cnt1=0;
        bool res1 = dfs(i, 0, cnt1, ids);
        for (int j = 0; j < ids.size(); ++j) {
          res[ids[j]] = -1;
        }
        int cnt2=0;
        ids.clear();
        bool res2 = dfs(i, 1, cnt2, ids);
        if (!res1 && !res2) {
          ans=-1;
          break;
        }
        int tmp=0;
        if (res1) {
          tmp = max(tmp, cnt1);
        }
        if (res2) {
          tmp=max(tmp, cnt2);
        }
        ans += tmp;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
