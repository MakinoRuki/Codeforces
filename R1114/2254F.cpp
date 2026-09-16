
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base = 337;

int n, m, q;
int k, w;
int t;

int a[N];
int b[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int xorA = 0;
    int xorB = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      xorA ^= a[i];
    }

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      xorB ^= b[i];
    }

    int x = xorA ^ xorB;
    int special = -1;

    if (x != 0) {
      for (int i = 1; i <= n; ++i) {
        if (a[i] == x) {
          special = i;
          break;
        }
      }
    }

    bool ok = true;

    // x不为0时，必须保留原数组中的一个x不变。
    if (x != 0 && special == -1) {
      ok = false;
    }

    vector<int> va;
    vector<int> vb;

    if (ok) {
      for (int i = 1; i <= n; ++i) {
        if (i == special) {
          va.push_back(a[i]);
        } else {
          va.push_back(a[i] ^ x);
        }

        vb.push_back(b[i]);
      }

      sort(va.begin(), va.end());
      sort(vb.begin(), vb.end());

      if (va != vb) {
        ok = false;
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
