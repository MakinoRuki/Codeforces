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
#define eps 1e-7
#define M 31
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t, l, r;
string s;
int main() {
  cin>>n;
  cin>>s;
  ll ans = 1LL;
  int cntl = 0;
  int i = 0;
  while(i < n && s[i] == s[0]) {
    i++;
  }
  ans= (ans + i) % mod2;
  if (i == n) {
    ans = (ans -1+mod2) % mod2;
  }
 // cout<<ans<<endl;
  int i2 = n-1;
  while(i2 >= 0 && s[i2] == s[n-1]) {
    i2--;
  }
  ans = (ans + n-1-i2) % mod2;
  if (i2 < 0) {
    ans=(ans-1+mod2)%mod2;
  }
 // cout<<ans<<endl;
  if (s[n-1] == s[0]) {
    if (i <= i2) {
      ans = (ans + (ll)i * (ll)(n-1-i2) % mod2) % mod2;
    }
  }
  cout<<ans<<endl;
  return 0;
}
