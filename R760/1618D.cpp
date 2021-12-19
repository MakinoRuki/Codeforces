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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    int i1 = n-2*k+1;
    int i2 = n-k+1;
    ll ans=0LL;
    for (int i = 0; i < k; ++i) {
      ans += a[i1+i] / a[i2+i];
    }
    for (int i = 1; i <= n-2*k; ++i) {
      ans += a[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
