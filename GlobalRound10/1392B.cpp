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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    ll mx = a[1], mn = a[1];
    for (int i = 2; i <= n; ++i) {
      mx=max(mx, a[i]);
      mn=min(mn, a[i]);
    }
    if (k % 2) {
      for (int i = 1; i <= n; ++i) {
        if (a[i] == mx) {
          a[i] = 0;
        } else if (a[i] == mn) {
          a[i] = mx-mn;
        } else {
          a[i] = mx-a[i];
        }
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (a[i] == mx) {
          a[i] = mx-mn;
        } else if (a[i] == mn) {
          a[i] = 0;
        } else {
          a[i] = a[i]-mn;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld", a[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
