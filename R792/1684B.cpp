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
#define N 200005
#define M 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    ll x = a + (ll)((c-a)/b+1)*(ll)b;
    ll y = b;
    ll z = c;
    printf("%lld %lld %lld\n", x, y, z);
  }
  return 0;
}
