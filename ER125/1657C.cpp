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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll b,x,y;
    scanf("%d%lld%lld%lld", &n, &b, &x, &y);
    ll tot = 0LL;
    ll sum = 0LL;
    for (int i = 1; i <= n; ++i) {
      if (sum + x <= b) {
        sum += x;
      } else {
        sum -= y;
      }
      tot += sum;
    }
    printf("%lld\n", tot);
  }
  return 0;
}
