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
#define N 65
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll comb[N][N];
int main() {
  comb[0][0] = 1LL;
  for (int i = 1; i <= 60; ++i) {
    comb[i][0] = 1LL;
    for (int j = 1; j <= i; ++j) {
      comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod2;
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll ans = 0LL;
    for (int i = n-1, j = n/2-1; i >= 0 && j >= 0; i -= 4, j -= 2) {
      ans = (ans + comb[i][j]) % mod2;
    }
    for (int i = n-4, j = n/2-3; i >= 0 && j >= 0; i -= 4, j -= 2) {
      ans = (ans + comb[i][j]) % mod2;
    }
    ll ans2 = (comb[n][n/2] - ans - 1 + mod2) % mod2;
    printf("%lld %lld %lld\n", ans, ans2, 1LL);
  }
  return 0;
}
