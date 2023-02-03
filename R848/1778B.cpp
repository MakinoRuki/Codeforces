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
#define N 100005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
int p[N];
int a[N];
int idx[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      idx[p[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &a[i]);
    }
    int ans = inf;
    for (int i = 1; i < m; ++i) {
      int id1 = idx[a[i]];
      int id2 = idx[a[i+1]];
      if (id1 >= id2 || id2 > id1 + d) {
        ans = 0;
        break;
      }
      ans = min(ans, id2-id1);
      int dt = id2-id1;
      if (d+1 <= n-1) {
        ans = min(ans, d+1-dt);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
