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
#define N 200005
#define M 300005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
ll sum[2][N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);
  // }
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(sum, 0LL, sizeof(sum));
  for (int i = 1; i <= n; ++i) {
    if (i == 1) sum[0][i] = 0;
    else sum[0][i] = sum[0][i-1] + max((ll)a[i-1]-a[i], 0LL);
  }
  for (int i= n; i >= 1; --i) {
    if (i == n) sum[1][i] = 0;
    else sum[1][i] = sum[1][i+1] + max((ll)a[i+1]-a[i], 0LL);
  }
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < y) {
      printf("%lld\n", sum[0][y]-sum[0][x]);
    } else {
      printf("%lld\n", sum[1][y] - sum[1][x]);
    }
  }
  return 0;
}
