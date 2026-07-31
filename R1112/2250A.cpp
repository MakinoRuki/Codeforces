
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

vector<pair<int, int> > v;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (n%2) {
      puts("No");
      continue;
    }
    int l = -1, r = inf;
    bool ok=true;
    for (int i = 1; i <= n; i += 2) {
      if (a[i] <= a[i+1]) {
        ok=false;
        break;
      }
      l = max(l, a[i+1]+1);
      r = min(r, a[i]-1);
    }
    if (ok && l <= r) {
      puts("Yes");
    } else {
      puts("No");
    }
  }

  return 0;
}
