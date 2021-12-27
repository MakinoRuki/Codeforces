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
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
int dp[N];
int sum[N][10];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
 // memset(sum, 0, sizeof(sum));
  for (int i = 0; i <= 1000000; ++i) {
    if (i < 10) dp[i] = i;
    else {
      int x = i;
      int res = 1;
      while(x) {
        if (x%10 > 0) {
          res *= (x%10);
        }
        x/=10;
      }
      dp[i] = dp[res];
    }
  }
  for (int i = 0; i <= 1000000; ++i) {
    if (i > 0) {
      for (int j = 0; j < 10; ++j) {
        sum[i][j] = sum[i-1][j];
      }
    }
    sum[i][dp[i]]++;
  }
  cin>>q;
  while(q-->0) {
    scanf("%d%d%d", &l, &r, &k);
    int res = sum[r][k];
    if (l-1>=0) res -= sum[l-1][k];
    printf("%d\n", res);
  }
  return 0;
}
