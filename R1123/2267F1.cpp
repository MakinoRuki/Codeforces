#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 2000005
using namespace std;
typedef long long ll;

int n, q;
int t;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &q);

    vector<int> a(n);
    vector<int> b;
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }

    b.reserve(n * (n - 1) / 2);

    while (true) {
      int lef = *min_element(a.begin(), a.end());
      int rig = *max_element(a.begin(), a.end());

      ans.push_back(rig - lef);

      if (rig == 0) {
        break;
      }

      b.clear();

      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          b.push_back(a[i] ^ a[j]);
        }
      }

      nth_element(b.begin(), b.begin() + n, b.end());

      for (int i = 0; i < n; ++i) {
        a[i] = b[i];
      }
    }

    for (int i = 1; i <= q; ++i) {
      int x;
      scanf("%d", &x);

      int res = 0;

      if (x < (int)ans.size()) {
        res = ans[x];
      }

      printf("%d\n", res);
    }
  }

  return 0;
}
