#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, q;
int s[N];
int dp[N][20];
int mr[N][20];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &s[i]);
  }
  memset(dp, 0, sizeof(dp));
  memset(mr, 0, sizeof(mr));
  //int m = (int)log(n)+1;
  int m = 19;
  for (int i = 1; i <= n; ++i) {
    mr[i][0] = s[i];
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (i+(1<<j) > n+1) continue;
      int sum = mr[i][j-1] + mr[i+(1<<(j-1))][j-1];
      dp[i][j] = dp[i][j-1]+dp[i+(1<<(j-1))][j-1];
      if (sum >= 10) dp[i][j]++;
      mr[i][j] = sum % 10;
    }
  }
  cin>>q;
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    int len = (r-l+1);
    int cnt=0;
    while((1<<cnt) < len) {
      cnt++;
    }
    cout<<dp[l][cnt]<<endl;
  }
  return 0;
}
