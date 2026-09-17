
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

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      cnt += x;
    }

    if (cnt >= n - cnt) {
      printf("Bessie\n");
    } else {
      printf("Elsie\n");
    }
  }

  return 0;
}
