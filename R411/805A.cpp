#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 500
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
ll calc(ll l, ll r, ll p) {
  return (r/p) - (l-1)/p;
}
int main() {
  ll l,r;
  cin>>l>>r;
  ll res=0, cnt=0;
  for (ll p = 2; p <= 20000000LL; ++p) {
    auto tmp = calc(l, r, p);
    if (tmp > cnt) {
      cnt=tmp;
      res=p;
    }
  }
  ll tmp = calc(l, r, l);
  if (tmp > cnt) {
    cnt=tmp;
    res=l;
  }
   tmp = calc(l, r, r);
  if (tmp > cnt) {
    cnt=tmp;
    res=r;
  }
  cout<<res<<endl;
  return 0;
}
