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
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int a[N];
int b[N];
int dp[N];
int p1[N], p2[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i <= n; ++i) {
    dp[i] = inf;
  }
  dp[n] = 0;
  memset(p1, -1, sizeof(p1));
  memset(p2, -1, sizeof(p2));
  queue<int> q;
  int ub = n+1;
  q.push(n);
  while(!q.empty()) {
    auto u = q.front();
    q.pop();
    for (int v = u-a[u]; v < ub; ++v) {
      if (v <= 0) {
        if (dp[0] > dp[u] + 1) {
          dp[0] = dp[u] + 1;
          p1[0] = 0;
          p2[0] = u;
        }
      } else {
        if (dp[v+b[v]] > dp[u] + 1) {
          dp[v+b[v]] = dp[u] + 1;
          p1[v+b[v]] = v;
          p2[v+b[v]] = u;
          q.push(v+b[v]);
        }
      }
    }
    ub = min(ub, u-a[u]);
  }
  if (dp[0] < inf) {
    vector<int> ps;
    ps.clear();
    int cur = 0;
    while(cur < n) {
      ps.push_back(p1[cur]);
      cur = p2[cur];
    }
    printf("%d\n", (int)ps.size());
    for (int i = ps.size()-1; i >= 0; --i) {
      printf("%d", ps[i]);
      if (i > 0) cout<<" ";
      else cout<<endl;
    } 
  } else {
    puts("-1");
  }
  return 0;
}
