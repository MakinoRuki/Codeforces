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
#define M 520
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int nn = min(n, 2002);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      dp[i] = -1;
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
      dp[i] = 1;
      for (int j = i-1; j >= max(0, i-500); --j) {
        if ((a[j] ^ i) < (a[i] ^ j)) {
          dp[i] = max(dp[i], dp[j]+1);
        }
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
