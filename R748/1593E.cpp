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
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
set<int> edges[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    queue<int> q;
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].insert(v);
      edges[v].insert(u);
    }
    for (int i = 1; i <=n; ++i) {
      if (edges[i].size() <= 1) {
        q.push(i);
      }
    }
    int tot=0;
    for (int i = 1; i <= k; ++i) {
      int sz=(int)q.size();
      for (int j = 0; j < sz; ++j) {
        int u = q.front();
        q.pop();
        tot++;
        for (auto v : edges[u]) {
          if (edges[v].empty()) continue;
          edges[v].erase(u);
          if (edges[v].size() <= 1) {
            q.push(v);
          }
        }
      }
    }
    printf("%d\n", max(0,n-tot));
  }
  return 0;
}
