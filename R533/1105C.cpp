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
#define N 200005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,l,r;
ll dp[N][3];
int main() {
  cin>>n>>l>>r;
  memset(dp, 0LL, sizeof(dp));
  dp[0][0] = 1LL;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = l; k < l+3; ++k) {
        if (k > r) continue;
        int r1 = k%3;
        int n1 = (r-k+1)/3;
        if ((r-k+1)%3) n1++;
        dp[i+1][(j+r1)%3] = (dp[i+1][(j+r1)%3]+dp[i][j]*(ll)n1%mod)%mod;
        // if (i==0&&j==0&&k==3) {
        //   cout<<i+1<<" "<<(j+r1)%3<<" "<<dp[i+1][(j+r1)%3]<<endl;
        // }
      }
    }
    //cout<<dp[1][0]<<" "<<dp[1][1]<<" "<<dp[1][2]<<endl;
  }
  cout<<dp[n][0]<<endl;
  return 0;
}
