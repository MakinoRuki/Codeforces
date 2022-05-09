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
#include <list>
#include <random>
#define N 200005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>n;
  int mn1 = inf, mn2 = inf;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] < mn1) {
      mn2 = mn1;
      mn1 = a[i];
    } else if (a[i] < mn2) {
      mn2 = a[i];
    }
  }
  int ans = inf;
  ans = (mn1+1)/2 + (mn2+1)/2;
  for (int i =2; i < n; ++i) {
    if (i-1>=1 && i+1<=n) {
      int dt = min(a[i-1], a[i+1]);
      int dt2 = max(a[i-1], a[i+1])-dt;
      dt2 = (dt2+1)/2;
      ans = min(ans, dt2 + dt);
    }
  }
  int l = 0, r = 3000000;
  while(l < r) {
    int mid = (l+r)/2;
    int i;
    for (i = 1; i < n; ++i) {
      if (max(0, a[i] - mid) + max(0, a[i+1]-mid) <= mid) {
        break;
      }
    }
    if (i < n) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  ans = min(ans, r);
  cout<<ans<<endl;
  return 0;
}
