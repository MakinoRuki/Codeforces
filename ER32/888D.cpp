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
#define M 500005
#define N 1005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
ll dp[N];
ll comb[N];
int main() {
  memset(dp, 0LL, sizeof(dp));
  dp[0] = 1;
  dp[1] = 0;
  dp[2] = 1;
  cin>>n>>k;
  for (int i = 3; i <= k; ++i) {
    dp[i] = (dp[i-1]+dp[i-2]) * (ll)(i-1);
  }
  comb[0] = 1LL;
  for (int i = 1; i <= k; ++i) {
    comb[i] = 1LL;
    for (int j = 0; j < i; ++j) {
      comb[i] *= (ll)(n-j);
    }
    for (int j = 1; j <= i; ++j) {
      comb[i] /= (ll)j;
    }
  }
  ll tot=0LL;
  for (int i = n-k; i <= n; ++i) {
    tot += comb[n-i] * dp[n-i];
  }
  cout<<tot<<endl;
  return 0;
}
