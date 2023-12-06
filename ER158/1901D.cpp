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
#define N 1000005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
ll lmx[N];
ll rmx[N];
bool check(ll x) {
  bool found=false;
  for (int i = 1; i <= n; ++i) {
    bool ok1=true;
    bool ok2=true;
    if (i > 1 && lmx[i-1] > x-n) {
      ok1=false;
    }
    if (i < n && rmx[i+1] > x+1) {
      ok2=false;
    }
    if (ok1 && ok2 && (x >= a[i])) {
      return true;
    }
  }
  return false;
}
int main() {
  cin>>n;
  for (int i =1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (i == 1) lmx[i] = a[i]-i;
    else lmx[i] = max(lmx[i-1], a[i]-i);
  }
  for (int i = n; i >= 1; --i) {
    if (i == n) rmx[i] = a[i]+i;
    else rmx[i] = max(rmx[i+1], a[i]+i);
  }
  ll l = 0, r= (1LL<<61)-1;
  while(l < r) {
    ll mid = (l+r)/2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  printf("%lld\n", r);
  return 0;
}
