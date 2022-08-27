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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int p[N];
int a[N];
int sum[2][N];
// int p2[N];
// ll getgcd(ll x, ll y) {
//   return y == 0 ? x : getgcd(y, x%y);
// }
// ll getlcm(ll x, ll y) {
//   return x / getgcd(x, y) * y;
// }
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
  //  ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll l = 0LL, r = 1000000000LL;
    while(l < r) {
      ll mid = (l+r+1)/2;
    //  cout<<"lr="<<l<<" "<<r<<" "<<mid<<endl;
      int tot=0;
      for (int i = 0; i <= n; ++i) {
        sum[0][i] = sum[1][i] = 0;
      }
      for (int i = 1; i <= n; ++i) {
        sum[0][i] = sum[0][i-1];
        sum[1][i] = sum[1][i-1];
        if (a[i] <= (mid+1)/2-1) {
          tot++;
          sum[1][i]++;
        }
        if (a[i] < mid) {
          sum[0][i]++;
        }
      }
      int res = n+1;
      int pre = 0;
      int pre2 = 0;
      for (int i = 1; i <= n; ++i) {
        int tmp = sum[0][i]-sum[1][i]+tot;
        if (i >= 2) res = min(res, tmp-pre2);
      //  if (mid == 12) cout<<"i="<<i<<" "<<tmp<<" "<<pre<<" "<<res<<endl;
        pre2 = max(pre2, pre);
        pre = max(pre, sum[0][i]-sum[1][i]);
      }
      if (res <= k) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
