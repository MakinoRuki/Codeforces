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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q;
int a[N];
//ll sum[N][460];
ll dp[N][460];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    // memset(sum, -1, sizeof(sum));
    int qr = (int)sqrt(2*n)+1;
    // for (int i = n; i >= 1; --i) {
    //   sum[i][1] = a[i];
    //   for (int j = 2; j <= 450; ++j) {
    //     if (i + j-1<=n) {
    //       sum[i][j] = sum[i+1][j-1]+a[i];
    //     } else {
    //       break;
    //     }
    //   }
    // }
    for (int i = 1; i <= n+2; ++i) {
      for (int j = 1; j <= 450; ++j) {
        dp[i][j] = -1;
      }
    }
    // memset(dp, -1, sizeof(dp));
    int len = 1;
    for (int i = n; i >= 1; --i) {
      // int now = n&1;
      // for (int j = 2; j <= 450; ++j) {
      //   dp[now][j] = -1;
      // }
      dp[i][1] = max(dp[i+1][1], (ll)a[i]);
      ll sum = a[i];
      for (int j = 2; j <= 450; ++j) {
        if (i+j-1 > n) break;
        dp[i][j] = dp[i+1][j];
        sum += a[i+j-1];
        if (i + j <= n && sum < dp[i+j][j-1]) {
          dp[i][j] = max(dp[i][j], sum);
        }
        // if (dp[i][j]>=0 && j==2) {
        //   cout<<"i="<<i<<" "<<endl;
        // }
        if (dp[i][j] >= 0) len = max(len, j);
      }
    }
    printf("%d\n", len);
  }
  return 0;
}
