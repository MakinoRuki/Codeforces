#include <iostream>
#include <sstream>
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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p;
int dp[N][2];
int calc(char c1, char c2) {
  if (c1 == c2) return 0;
  return 1;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1, s2;
    cin>>s1>>s2;
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = inf;
      dp[i][1] = inf;
    }
    dp[0][0]=0,dp[0][1]=0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (dp[i][j] < inf) {
          dp[i+1][0] = min(dp[i+1][0], dp[i][j]+calc(s1[i], s2[i]));
          if (i+2<=n) dp[i+2][1] = min(dp[i+2][1], dp[i][j]+calc(s1[i], s1[i+1])+calc(s2[i], s2[i+1]));
        }
      }
    }
    int ans=min(dp[n][0], dp[n][1]);
    printf("%d\n", ans);
  }
  return 0;
}

