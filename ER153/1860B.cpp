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
#include <ctime>
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    //scanf("%d", &n);
    ll m, k, a1, ak;
    scanf("%lld%lld%lld%lld", &m, &k, &a1, &ak);
    ll x1 = 0, x2 = 0;
    ll y1 = 0, y2 = 0;
    x1 = min(ak, m/k);
    x2 = max(0LL, m/k-ak);
    y1 = min(a1, m%k);
    y2 = max(0LL, m%k-a1);
    if (y2 == 0 && y1 <= a1) {
      ll dt = a1 - (y1);
      dt /= k;
      x2 -= min(x2, dt);
    }
    printf("%lld\n", y2 + x2);
  }
  return 0;
}
