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
#define M 52
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, h;
int k;
int q, p;
int a[N], b[N];
ll dp[N][N];
int main() {
  cin>>n>>k>>p;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = (1LL<<61)-1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &b[i]);
  }
  sort(b+1, b+k+1);
  dp[0][0] = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] < (1LL<<61)-1) {
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        if (j + 1 <= n) {
          ll dt = abs(b[i+1]-a[j+1]) + abs(b[i+1] - p);
        //  if (i==1 && j==0) cout<<"v1="<<dp[i][j]<<" "<<dt<<endl;
          dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], dt));
        //  if (i==1 && j==0) cout<<"v2="<<dp[i+1][j+1]<<endl;
        }
      }
    }
  }
//  cout<<dp[2][1]<<endl;
  cout<<dp[k][n]<<endl;
  return 0;
}
