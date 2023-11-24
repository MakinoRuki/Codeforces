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
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int mn[N];
ll tot;
bool check(ll x) {
  int l = 0, r= n;
  while(l < r) {
    int mid= (l+r+1)/2;
    if (a[mid] < x) {
      l = mid;
    } else {
      r = mid-1;
    }
  }
  if (r >= 1) {
    if (mn[r] + k < x) {
      return false;
    }
  }
  if (r > k) {
    return false;
  }
  if (n-r >= 2) {
    return true;
  }
  if ((k-r)%2) {
    if (r >= n) return false;
    else {
      if (n > r) return true;
      r++;
    }
  }
  ll dt= (2LL*k-r+1) * (ll)r / 2LL;
  dt = dt + tot;
  dt -= (ll)x * n;
  if (dt >= (k-r)/2) return true;
  return false;
}
int main() {
  cin>>n>>q;
  tot = 0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    tot += (ll)a[i];
  }
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) {
    mn[i] = (i == 1 ? a[i]-i+1 : min(mn[i-1], a[i]-i+1));
  }
  vector<ll> ans;
  ans.clear();
  while(q-->0) {
    scanf("%d", &k);
    ll l = -1e18, r = 1e18;
    while(l < r) {
      ll mid = (l+r+1)/2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    ans.push_back(r);
  }
  for (int i = 0 ; i < ans.size(); ++i) {
    printf("%lld ", ans[i]);
  }
  cout<<endl;
  return 0;
}
