
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
char c;
char s[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d %c", &n, &c);
    scanf("%s", s + 1);

    int ans = 0;

    for (int i = 1; i <= n / 2; ++i) {
      int j = n - i + 1;

      if (s[i] != s[j]) {
        if (s[i] == c || s[j] == c) {
          ++ans;
        } else {
          ans += 2;
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
