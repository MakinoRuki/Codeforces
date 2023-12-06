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
int a[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1 ; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll tot=0LL;
    for (int i = 2; i <= n; ++i) {
      if (a[i] > a[i-1]) {
        tot += a[i]-a[i-1];
      }
    }
    if (a[1] > 1) {
      tot += a[1]-1;
    }
    printf("%lld\n", tot);
  }
  return 0;
}
