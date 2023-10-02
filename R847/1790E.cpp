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
#define N 200010
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
    ll x;
    scanf("%lld", &x);
    if (x % 2) {
      puts("-1");
      continue;
    }
    ll y = x/2;
    if ( (y & x) > 0) {
      puts("-1");
      continue;
    }
    printf("%lld %lld\n", y, x^y);
  }
  return 0;
}
