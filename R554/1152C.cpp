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
#define N 2002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
ll a, b;
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  scanf("%lld%lld", &a, &b);
  if (a > b) swap(a, b);
  ll d = b-a;
  ll ans=a/getgcd(a,b)*b;
  ll k = 0;
  for (ll i = 1; i * i <= d; ++i) {
    if (d % i == 0) {
      ll k2 = i-a%i;
      ll g = getgcd(a+k2, b+k2);
      ll res = (a+k2)/g*(b+k2);
      if (res < ans) {
        ans = res;
        k = k2;
      }
      if (d/i != i) {
        k2 = d/i - a%(d/i);
        g = getgcd(a+k2, b+k2);
        res = (a+k2)/g*(b+k2);
        if (res < ans) {
          ans = res;
          k = k2;
        }
      }
    }
  }
  cout<<k<<endl;
  return 0;
}
