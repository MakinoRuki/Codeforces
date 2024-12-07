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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
int t;
int a[N];
int dp[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int n1 = (int)s1.size();
    int n2 = (int)s2.size();
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            int k = i+j+1;
            if (k <= (int)s3.size()) {
                if (i+1<=n1) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (s3[k-1] != s1[i]));
                if (j+1<=n2) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + (s3[k-1] != s2[j]));
            }
        }
    }
    int ans=dp[n1][n2];
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

