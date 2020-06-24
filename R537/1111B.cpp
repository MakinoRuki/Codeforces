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
#define N 100005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m, k;
ll tot;
ll a[N];
int main() {
  tot=0LL;
  cin>>n>>k>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    tot += a[i];
  }
  sort(a+1, a+n+1);
  ll x = tot + min((ll)n*(ll)k, (ll)m);
  ll y = n;
  for (int i = 1; i < n; ++i) {
    if (m < i) break;
    tot -= a[i];
    ll tot2 = tot + min((ll)(n-i)*(ll)k, (ll)max(0, m-i));
    if (tot2*y > x*(n-i)) {
    //  cout<<i<<" "<<tot2<<endl;
      x = tot2;
      y = n-i;
    }
  }
  double ans = (double)x/(double)y;
  printf("%.7lf\n", ans);
  return 0;
}
