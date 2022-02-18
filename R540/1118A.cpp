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
#define M 202
#define N 1005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int main() {
  cin>>q;
  for (int cas=1; cas<=q; ++cas) {
    ll n;
    int a,b;
    scanf("%lld%d%d", &n, &a, &b);
    if (b < 2*a) {
      ll res = n/2*b + (n%2)*a;
      printf("%lld\n", res);
    } else {
      ll res = n * a;
      printf("%lld\n", res);
    }
  }
  return 0;
}
