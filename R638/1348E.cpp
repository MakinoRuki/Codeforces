#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 505
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
bool dp[N][N];
int main() {
  cin>>n>>k;
  memset(dp, false, sizeof(dp));
  dp[0][0] = true;
  ll sum=0LL;
  for (int i = 1; i <= n; ++i) {
    int a,b;
    scanf("%d%d", &a, &b);
    sum += (a+b);
    for (int j = 0; j < k; ++j) {
      if (!dp[i-1][j]) continue;
      for (int t = 0; t < k; ++t) {
        int det = (t-j+k) % k;
        if (det <= a && (((a-det+k)%k==0) || (b >= k-(a-det+k)%k))) {
          dp[i][t] |= dp[i-1][j];
        }
      }
    }
  }
 // cout<<dp[1][2]<<" "<<dp[2][0]<<endl;
  ll ans=0LL;
  for (int i = 0; i < k; ++i) {
    if (dp[n][i]) {
      ans = max(ans, (sum-i)/k);
    }
  }
  cout<<ans<<endl;
  return 0;
}
