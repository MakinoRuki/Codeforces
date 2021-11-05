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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, h;
int k;
int q;
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>n;
  ll a,b;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld", &a, &b);
    ll l = 1, r = 1000000LL;
    while(l < r) {
      ll mid = (l+r+1)/2;
      if (mid*mid <= (a*b)/mid) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    if ((a%r==0) && (b%r==0) && ((a*b)%r == 0) && (r * r == (a*b)/r)) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
