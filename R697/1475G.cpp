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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int dp[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= 200000; ++i) {
      cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    for (int i = 1; i <= 200000; ++i) {
      dp[i] = cnt[i];
    }
    int ans=0;
    for (int i = 1; i <= 200000; ++i) {
      ans = max(ans, dp[i]);
      for (int j = 2*i; j <= 200000; j += i) {
        dp[j] = max(dp[j], dp[i] + cnt[j]);
      }
    }
    ans = n-ans;
    printf("%d\n", ans);
  }
  return 0;
}
