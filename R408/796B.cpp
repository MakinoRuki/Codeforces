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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int a[N];
bool h[N];
vector<pair<int,int>> q;
int main() {
  cin>>n>>m>>k;
  memset(h, false, sizeof(h));
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    h[x] = true;
  }
  q.clear();
  for (int i = 1; i <= k; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    q.push_back(make_pair(u, v));
  }
  int cur = 1;
  for (int i = 1; i <= k; ++i) {
    int u, v;
    u = q[i-1].first;
    v = q[i-1].second;
    if (h[cur]) break;
    if (u == cur) cur = v;
    else if (v == cur) cur = u;
    if (h[cur]) break;
  }
  printf("%d\n", cur);
  return 0;
}
