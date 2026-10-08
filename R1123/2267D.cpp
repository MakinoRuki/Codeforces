
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 200005
using namespace std;
typedef long long ll;

int n;
int t;
int pos[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      pos[x] = i;
    }

    int ok = 1;

    for (int i = n; i >= 2; i -= 2) {
      if ((pos[i] & 1) == (pos[i - 1] & 1)) {
        ok = 0;
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
