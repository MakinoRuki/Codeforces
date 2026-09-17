
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 55
using namespace std;
typedef long long ll;

int n;
int t;
int a[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);

      if (a[i] == 0) {
        ++cnt;
      }
    }

    if (cnt < 2) {
      printf("-1\n");
    } else {
      printf("%d\n", a[1] + a[n]);
    }
  }

  return 0;
}
