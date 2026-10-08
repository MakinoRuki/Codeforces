
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;

int n, x;
int t;
ll sum[N];
vector<int> fac[N];

int main() {
  for (int i = 2; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      fac[j].push_back(i);
    }
  }

  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &x);

    for (int d : fac[x]) {
      sum[d] = 0;
    }

    for (int i = 1; i <= n; ++i) {
      int a;
      scanf("%d", &a);

      for (int d : fac[a]) {
        if (x % d == 0) {
          sum[d] += a;
        }
      }
    }

    ll ans = 0;

    for (int d : fac[x]) {
      ans = max(ans, sum[d]);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
