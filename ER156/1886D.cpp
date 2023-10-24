#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
ll ans;
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
int main() {
  cin>>n>>m;
  string s;
  cin>>s;
  ans = 1LL;
  for (int i = 3; i <= n; ++i) {
    if (s[i-2] == '?') {
      ans = ans * (ll)(i-2) % mod2;
    }
  }
  if (s[0] == '?') {
    puts("0");
  } else {
    printf("%lld\n", ans);
  }
  for (int i = 1; i <= m; ++i) {
    int pos;
    scanf("%d", &pos);
    string ss;
    cin>>ss;
    if (pos != 1) {
      if (s[pos-1] == '?' && ss[0] != '?') {
        ans = ans * getpw(pos-1, mod2-2) % mod2;
      } else if (s[pos-1] != '?' && ss[0] == '?') {
        ans = ans * (ll)(pos-1) % mod2;
      }
    }
    s[pos-1] = ss[0];
    if (s[0] == '?') {
      puts("0");
    } else {
      printf("%lld\n", ans);
    }
  }
  return 0;
}
