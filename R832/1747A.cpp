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
#define N 5002
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
    ll s1 = 0, s2=0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      ll x;
      scanf("%lld", &x);
      if (x >= 0) s1 += x;
      else s2 += abs(x);
    }
    printf("%lld\n", max(s1,s2)-min(s1,s2));
  }
  return 0;
}
