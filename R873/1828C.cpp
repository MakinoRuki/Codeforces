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
#include <list>
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    sort(b+1, b+n+1);
    sort(a+1, a+n+1);
    int cur=n;
    ll ans=1LL;
    for (int i = n; i >= 1; --i) {
      while(cur >= 1 && a[cur] > b[i]) {
        cur--;
      }
      int dt = n-cur;
      dt -= (n-i);
      if (dt <= 0) {
        ans = 0LL;
        break;
      }
      ans = ans * (ll)dt % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
