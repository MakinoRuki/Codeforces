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
#define N 600
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
ll a[N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot = 0LL;
    for (int i = 0; i < 2*n; ++i) {
      for (int j = 0; j < 2*n; ++j) {
        scanf("%lld", &a[i][j]);
        if (i >= n && j >= n) {
          tot += a[i][j];
        }
      }
    }
    ll res = a[0][n];
    res = min(res, a[0][2*n-1]);
    res = min(res, a[n-1][n]);
    res = min(res, a[n-1][2*n-1]);
    res = min(res, a[n][0]);
    res = min(res, a[n][n-1]);
    res = min(res, a[2*n-1][0]);
    res = min(res, a[2*n-1][n-1]);
    printf("%lld\n", tot + res);
  }
  return 0;
}
