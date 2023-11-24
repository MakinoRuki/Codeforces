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
#define N 1000005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll ans[N];
ll res[M][M];
int main() {
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      res[i][j] = 0;
    }
  }
  for (int i = 0; i < N; ++i) {
    ans[i] = 0;
  }
  ll cur = 1;
  for (int i = 1; i < M; ++i) {
    int r = i, c = 1;
    for (int r = i, c = 1; r > 0; r--, c++) {
      res[r][c] = res[r-1][c] + res[r][c-1] - res[r-1][c-1] + cur*cur;
      if (cur > 1000000) break;
      ans[cur++] = res[r][c];
    }
    if (cur > 1000000) break;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", ans[n]);
  }
  return 0;
}
