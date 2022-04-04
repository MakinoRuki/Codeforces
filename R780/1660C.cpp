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
#define M 202
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
int a[N];
string s;
int dp[N][26][2];
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    cin>>s;
    n = (int)s.size();
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 26; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = inf;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      dp[i][s[i]-'a'][0] = i;
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 26; ++j) {
        for (int k = 0; k < 2; ++k) {
          if (dp[i][j][k] < inf) {
            dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]+1);
            if (k == 0 && i + 1 < n && s[i+1]-'a' == j) {
            //  if (i+1 == n-1 && j== 23) cout<<"v="<<i<<" "<<j<<" "<<k<<endl;
              dp[i+1][j][1] = min(dp[i+1][j][1], dp[i][j][k]);
            }
            if (i+1 < n && k == 1) {
              dp[i+1][s[i+1]-'a'][0] = min(dp[i+1][s[i+1]-'a'][0], dp[i][j][k]);
            }
          }
        }
      }
    }
    for (int i = 0; i < 26; ++i) {
    //  if (dp[n-1][i][1] == 0) cout<<"i="<<i<<endl;
      ans=min(ans, dp[n-1][i][1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
