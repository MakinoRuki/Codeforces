#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, d, k;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll s,a,b,c;
    scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
    ll x = s/(c*a);
    ll y = s%(c*a);
    ll ans = x*(a+b) + y/c;
    printf("%lld\n", ans);
  }
  return 0;
}
