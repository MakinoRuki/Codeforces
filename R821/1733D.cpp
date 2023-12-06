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
#define N 5002
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
string a,b;
ll dp[N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x,y;
    scanf("%d%lld%lld", &n, &x, &y);
    cin>>a;
    cin>>b;
    vector<int> ids;
    ids.clear();
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        ids.push_back(i);
      }
    }
    int sz = (int)ids.size();
    if (sz % 2) {
      puts("-1");
      continue;
    }
    if (sz == 0) {
      puts("0");
      continue;
    }
    if (y <= x) {
      if (sz > 2 || ids[0]+1!=ids[1]) {
        printf("%lld\n", (ll)(sz/2)*y);
      } else {
        printf("%lld\n", min(2LL*y, x));
      }
      continue;
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = (1LL<<61)-1;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (dp[i][j] < (1LL<<61)-1) {
          if (j) dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]+y);
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
          ll dt = x * (ll)(ids[i+1]-ids[i]);
          dp[i+2][j] = min(dp[i+2][j], dp[i][j]+dt);
        }
      }
    }
    printf("%lld\n", dp[sz][0]);
  }
  return 0;
}
