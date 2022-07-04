#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N], b[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n>>m;
  ll res=0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    res += (ll)a[i];
  }
  if (res <= m) {
    puts("-1");
    return 0;
  }
  double l = 0.0, r = 20000000000.0;
  for (int i = 1; i <= 200; ++i) {
    double mid = (l+r)*0.5;
   // cout<<l<<" "<<r<<" "<<mid<<endl;
    double tot=0.0;
    for (int j = 1; j <= n; ++j) {
      tot += fabs(min(0.0, b[j] - a[j] * mid));
    }
    if (tot + eps < mid * m) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.10lf\n", r);
  return 0;
}
