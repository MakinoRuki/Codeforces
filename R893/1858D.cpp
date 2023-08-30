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
#define N 3002
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int pre[N][N];
int suf[N][N];
int dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    for (int i = 0; i <= n+1; ++i) {
      for (int j = 0; j <= n; ++j) {
        pre[i][j] = 0;
        suf[i][j] = 0;
      }
      dp[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
      int cnt=0;
      for (int j = i; j <= n; ++j) {
        if (s[j-1] == '1') cnt++;
       // if (i==1&&j==3)cout<<"cnt="<<cnt<<endl;
        pre[j][cnt] = max(pre[j][cnt], j-i+1);
        suf[i][cnt] = max(suf[i][cnt], j-i+1);
      }
    }
   // cout<<"dp="<<pre[3][0]<<endl;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        pre[i][j] = max(pre[i][j], pre[i-1][j]);
        if (j>0) pre[i][j] = max(pre[i][j], pre[i][j-1]);
      }
    }
    for (int i = n; i >= 1; --i) {
      for (int j = 0; j <= k; ++j) {
        suf[i][j] = max(suf[i][j], suf[i+1][j]);
        if (j) suf[i][j] = max(suf[i][j], suf[i][j-1]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        dp[0] = max(dp[0], pre[i][j]);
        dp[0] = max(dp[0], suf[i][j]);
      }
    }
    for (int l = 1; l <= n; ++l) {
      int cnt=0;
      for (int r = l; r <= n; ++r) {
        if (s[r-1] == '0') cnt++;
       // if (l == 4 && r == 7) cout<<"vv="<<k<<" "<<cnt<<" "<<pre[l-1][k-cnt]<<" "<<suf[r+1][k-cnt]<<endl;
        if (cnt <= k) dp[r-l+1] = max(dp[r-l+1], max(pre[l-1][k-cnt], suf[r+1][k-cnt]));
      }
    }
  //  cout<<"v="<<dp[4]<<endl;
    for (int x = 1; x <= n; ++x) {
      int res=0;
      for (int i = 0; i <= n; ++i) {
        if (dp[i] >= 0) res = max(res, x * dp[i] + i);
        //if (x == 1) cout<<"i="<<i<<" "<<dp[i]<<endl;
      }
      printf("%d", res);
      if (x < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
