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
#define N 40000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int a[N];
int b[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  // for (int i = 15; i >= 0; --i) {
  //   if ((1<<i) & 10240) {
  //     cout<<1;
  //   } else {
  //     cout<<0;
  //   }
  // }
  // cout<<endl;
  ll ans = 0LL;
  for (int i =1 ; i <= n; ++i) {
    ll minv = (1LL<<61)-1;
    for (int j = 0; j <= 15; ++j) {
      ll det = a[i] % (1LL<<j);
      if (det != 0) {
        minv = min(minv, 15LL-j + (1LL<<j) - det);
      } else {
        minv = min(minv, 15LL-j);
      }
    }
    printf("%lld", minv);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  //cout<<ans<<endl;
  return 0;
}
