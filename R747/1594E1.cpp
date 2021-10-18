#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#define eps 1e-7
#define M 502
#define N 500002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin>>k;
  ll ans = 6LL;
  ll sum = 1LL;
  for (int i = 1; i <= k-1; ++i) {
    sum = sum * getpw(4LL, (1LL<<i)) % mod;
  }
  //cout<<sum<<endl;
  //sum = getpw(4LL, sum) % mod;
  //cout<<sum<<endl;
  ans = ans * sum % mod;
  cout<<ans<<endl;
  return 0;
}
