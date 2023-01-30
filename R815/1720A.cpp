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
#define N 50005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll a,b,c,d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if (a == 0 && c == 0) {
      puts("0");
      continue;
    } else if (a == 0 || c == 0) {
      puts("1");
      continue;
    }
    ll x = a*d;
    ll y = b*c;
    ll g = getgcd(x, y);
    x /= g;
    y /= g;
    if (x == y) {
      puts("0");
    } else {
      if (((x % y) == 0) || ((y % x) == 0)) {
        puts("1");
      } else {
        puts("2");
      }
    }
  }
  return 0;
}
