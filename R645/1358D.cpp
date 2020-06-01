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
//#include <priority_queue>
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
ll x;
ll d[N];
ll sum1[N], sum2[N];
int main() {
  scanf("%d%lld", &n, &x);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &d[i]);
  }
  for (int i = n+1; i <= 2*n; ++i) {
    d[i] = d[i-n];
  }
  sum1[0] = 0LL;
  sum2[0] = 0LL;
  ll ans=0LL;
  for (int i = 1; i <= 2*n; ++i) {
    sum1[i] = sum1[i-1]+d[i];
    sum2[i] = sum2[i-1]+(d[i]*(d[i]+1)/2);
  }
  for (int i = 1; i <= n; ++i) {
    int l = 1, r = 2*n;
    while(l < r) {
      int mid = (l+r)/2;
      if (sum1[mid]-sum1[i-1] < x) {
        l = mid+1; 
      } else {
        r = mid;
      }
    }
    ll det = sum1[r]-sum1[i-1]-x;
    if (1+det<=d[i]) {
      ll res = sum2[r]-sum2[i-1];
      ll det2 = det*(det+1)/2;
      ans = max(ans, res-det2);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
