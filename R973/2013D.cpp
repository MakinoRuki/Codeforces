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
#include <list>
#include <stack>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
ll a[N];
int b[N];
ll sum[N];
bool check1(ll x) {
  ll dt = 0LL;
  for (int i = 1; i <= n; ++i) {
    ll tmp = dt + a[i];
    if (tmp < x) return false;
    dt = tmp - x;
  }
  return true;
}
bool check2(ll x) {
  ll dt = 0LL;
  for (int i = 1; i <= n; ++i) {
    ll tmp = dt + a[i];
    if (tmp > x) {
      dt = tmp - x;
    } else {
      dt = 0;
    }
  }
  return dt <= 0;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d", &n);
    sum[0] = 0LL;
    ll tot = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      sum[i] = sum[i-1] + a[i];
    }
    tot = sum[n];
    ll mn = -1, mx = -1;
    ll l = 0, r = tot;
    while(l < r) {
      ll mid = (l+r+1)/2;
      if (check1(mid)) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    mn = r;
    l = 0, r = tot;
    while(l < r) {
      ll mid = (l+r)/2;
      if (check2(mid)) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    mx = r;
    printf("%lld\n", mx - mn);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

