
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
int cnt[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));

    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      ++cnt[x];
    }

    vector<int> ans;

    for (int x = 100; x >= 1; --x) {
      if (cnt[x] == 0) {
        continue;
      }

      int k = cnt[x];

      for (int y = x; y >= 1; --y) {
        int num = min(cnt[y], k);
        cnt[y] -= num;

        for (int j = 1; j <= num; ++j) {
          ans.push_back(y);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
  }

  return 0;
}
