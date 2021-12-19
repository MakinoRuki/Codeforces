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
#define N 200
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
ll a[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x % y);
}
ll getg(vector<ll>& v) {
  ll g = v[0];
  for (int i = 1; i < v.size(); ++i) {
    g = getgcd(g, v[i]);
  }
  return g;
}
bool check(vector<ll>& v, ll g) {
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] % g == 0) return false;
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<ll> v1, v0;
    v1.clear();
    v0.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      if (i % 2) v1.push_back(a[i]);
      else v0.push_back(a[i]);
    }
    ll g0 = getg(v0);
    ll g1 = getg(v1);
    if (g0 == g1) {
      puts("0");
    } else {
      if (check(v0, g1)) {
        printf("%lld\n", g1);
      } else if (check(v1, g0)) {
        printf("%lld\n", g0);
      } else {
        puts("0");
      }
    }
  }
  return 0;
}
