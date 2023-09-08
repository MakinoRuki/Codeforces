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
#define N 200
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
int d[N], s[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n,x,y;
    scanf("%lld%lld%lld", &n, &x, &y);
    ll g = getgcd(x, y);
    ll lcm = x/g*y;
    ll n1 = n/x-n/lcm;
    ll n2 = n/y-n/lcm;
    ll ans = 0LL;
    if (n1 > 0) {
      ans += n*n1;
      ans -= n1*(n1-1)/2;
    }
    ans -= n2*(n2+1)/2;
    printf("%lld\n", ans);
  }
  return 0;
}
