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
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll a,b;
    scanf("%lld%lld", &a, &b);
    ll ans = -1;
    for (ll s = 1; s <= 200000; ++s) {
      ll res = s-1+(a+s-1)/s+(b+s-1)/s;
      ans = (ans < 0 ? res : min(ans, res));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
