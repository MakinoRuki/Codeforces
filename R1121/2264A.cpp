
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 105
using namespace std;
typedef long long ll;

int n;
int t;
int p[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int pre = n + 1;
    int ok = 1;

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);

      if (p[i] != i) {
        if (p[i] >= pre) {
          ok = 0;
        }

        pre = p[i];
      }
    }

    if (ok) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
