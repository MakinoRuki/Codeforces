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
#define N 1000005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x,y;
    scanf("%lld%lld", &x, &y);
    printf("%lld\n", 2*(x-y));
    for (ll i = x; i >= y; --i) {
      printf("%lld ", i);
    }
    for (ll i = y+1; i < x; ++i) {
      printf("%lld ", i);
    }
    cout<<endl;
  }
  return 0;
}
