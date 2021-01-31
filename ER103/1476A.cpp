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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll n, k;
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld%lld",&n,&k);
    if (n < k) {
      // ll g = getgcd(n,k);
      // ll res = n*(k/g);
      // res /= n;
      ll res = k/n;
      if (k%n > 0) res++;
      printf("%lld\n", res);
    } else {
      ll r = n%k;
      if (r==0) {
        printf("%d\n", 1);
      } else {
        printf("%d\n", 2);
      }
    }
  }
  return 0;
}
