#include <iostream>
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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
bool check(vector<int> rk, int x, int y) {
  sort(rk.begin(), rk.end());
  reverse(rk.begin(), rk.end());
  ll tot=0, rem=0;
  for (int i = 0; i < rk.size(); ++i) {
    if (tot + 2 <= y) {
      tot += 2;
      rem += rk[i]-2;
    } else {
      break;
    }
  }
  return tot + rem >= y;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok = false;
    vector<int> rk;
    rk.clear();
    for (int i = 1; i <= k; ++i) {
      if (a[i] / m >= 2) {
        rk.push_back(a[i]/m);
      }
    }
    ok |= check(rk, m, n);
    rk.clear();
    for (int i = 1; i <= k; ++i) {
      if (a[i]/n >= 2) {
        rk.push_back(a[i]/n);
      }
    }
    ok |= check(rk, n, m);
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
