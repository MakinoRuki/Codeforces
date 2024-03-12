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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n*m; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n*m+1);
    ll dt = a[n*m]-a[1];
    ll tot = dt * (ll)(n*m - (n+m-1));
  //  cout<<"tot="<<tot<<" "<<dt<<endl;
    if (n == 1 || m == 1) {
      printf("%lld\n", tot);
    } else {
      ll dt1 = a[n*m]-a[1];
      ll dt2 = a[n*m-1]-a[1];
      ll dt3 = a[n*m]-a[2];
      ll dt=0LL;
      if (n < m) {
        dt = (ll)(n-1)*min(dt1, dt2)+(ll)(m-1)*max(dt1,dt2);
        dt = max(dt, (ll)(n-1)*min(dt1, dt3)+(ll)(m-1)*max(dt1,dt3));
      } else {
        dt = (ll)(m-1)*min(dt1, dt2)+(ll)(n-1)*max(dt1,dt2);
        dt = max(dt, (ll)(m-1)*min(dt1, dt3)+(ll)(n-1)*max(dt1,dt3));
      }
      tot += dt;
      printf("%lld\n", tot);
    }
  }
  return 0;
}
