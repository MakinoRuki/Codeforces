
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;

int n, m;
int t;
ll a[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }

    priority_queue<ll> q;
    ll sum = 0;
    ll ans = -(1LL << 60);

    for (int i = 1; i <= n; ++i) {
      if (i >= m) {
        ans = max(ans, 1LL * m * a[i] - sum);
      }

      q.push(a[i]);
      sum += a[i];

      if ((int)q.size() > m - 1) {
        sum -= q.top();
        q.pop();
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}
