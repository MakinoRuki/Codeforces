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
#define N 300005
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
int dp[N];
map<int, int> mp;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      dp[i] = (1LL<<61)-1;
    }
    dp[0] = 0LL;
    mp.clear();
    mp[0] = 0;
    int sum=0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i-1] + 1;
      sum ^= a[i];
      if (mp.find(sum) != mp.end()) {
        dp[i] = min(dp[i], mp[sum]-1+i);
        mp[sum] = min(mp[sum], dp[i]-i);
      } else {
        mp[sum] = dp[i]-i;
      }
    }
    printf("%d\n", dp[n]);
  }
  return 0;
}
