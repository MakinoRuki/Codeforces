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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll ans[N];
int a[N];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ll sum=0LL;
  ans[0] = 0LL;
  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      sum=1LL;
    } else {
      if (a[i] == a[i-1]) sum++;
      else sum += i;
    }
    ans[i] = ans[i-1] + sum;
  }
 // cout<<ans[n]<<endl;
  for (int i= 1; i <= m; ++i) {
    int p, x;
    scanf("%d%d", &p, &x);
    if (a[p] == x) {
      printf("%lld\n", ans[n]);
    } else {
      if (p > 1) {
        if ((a[p-1] != a[p]) && (x==a[p-1])) {
          ans[n] += (ll)(-p+1)*(ll)(n-p+1);
        } else if ((a[p-1]==a[p]) && (x!=a[p])) {
          ans[n] += (ll)(p-1)*(ll)(n-p+1); 
        }
      }
      if (p < n) {
        if ((a[p] != a[p+1]) && (x==a[p+1])) {
          ans[n] += (ll)(-p)*(ll)(n-p);
        } else if ((a[p]==a[p+1]) && (x!=a[p+1])) {
          ans[n] += (ll)p*(ll)(n-p);
        }
      }
      a[p]=x;
      printf("%lld\n", ans[n]);
    }
  }
  return 0;
}
