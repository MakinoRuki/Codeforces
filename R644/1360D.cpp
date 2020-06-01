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
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll n, k;
int main() {
  cin>>t;
  for (int i = 1; i <= t; ++i) {
    scanf("%lld%lld", &n, &k);
    ll ans=n;
    for (ll j = 1; j*j <= n; ++j) {
      if (n%j==0) {
        if (j <= k) {
          ans =min(ans, n/j);
        }
        if (n/j <= k) {
          ans = min(ans, n/(n/j));
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
