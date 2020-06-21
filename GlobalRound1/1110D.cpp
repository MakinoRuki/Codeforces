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
#define N 1000005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int a[N];
int dp[N][3][3];
int cnt[N];
int main() {
  cin>>n>>m;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j1 = 0; j1 < 3; ++j1) {
      for (int j2 = 0; j2 < 3; ++j2) {
        if (dp[i][j1][j2] >= 0) {
          for (int k = 0; k < 3; ++k) {
            if (j1+j2+k <= cnt[i+1]) {
              dp[i+1][j2][k] = max(dp[i+1][j2][k], dp[i][j1][j2] + j1 + (cnt[i+1]-j1-j2-k)/3);
            }
          }
        }
      }
    }
  }
  cout<<dp[m][0][0]<<endl;
  return 0;
}
