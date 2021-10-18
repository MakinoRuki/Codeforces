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
#include <stack>
#define eps 1e-7
#define M 502
#define N 50002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
ll n;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld", &n);
    ll a = 2LL, b = n;
    while(b % 2 == 0) {
      a *= 2LL;
      b /= 2LL;
    }
    ll r = (a+ b-1)/2;
    ll l = (b-a+1)/2;
    if (r < l) swap(l,r);
    printf("%lld %lld\n", l, r);
  }
  return 0;
}
