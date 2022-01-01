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
#define N 400005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
ll a[N];
int ans[N];
string s;
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);
    sum[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1] + a[i];
    }
    ll ans = -1;
    ll det = sum[n] - sum[1];
    det = k-det;
    ans = max(0LL, a[1] - det);
    for (int i = n; i >= 2; --i) {
      ll det = sum[i-1] - sum[1];
   //   if (i == n) cout<<"det="<<det<<" "<<k<<endl;
      det = k-det;
      if (det >= 0) {
        ll tot = det / (n-i+1+1);
        tot = max(a[1] - tot, 0LL);
     //   if (i == n) cout<<"tot="<<tot<<endl;
        ans = (ans < 0 ? tot + n-i+1 : min(ans, tot+n-i+1));
      } else {
        ll det2 = -det;
        ll tot = (det2 + n-i+1) / (n-i+2);
        tot = -tot;
        tot = max(a[1] - tot, 0LL);
        ans = (ans < 0 ? tot + n-i+1 : min(ans, tot+n-i+1));
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
