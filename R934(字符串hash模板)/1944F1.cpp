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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int dp[2][M][M];
int sum[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int p;
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int j2 = 0; j2 <= n; ++j2) {
                dp[i][j][j2] = 0;
            }
        }
    }
    for (int i = 0; i <= k; ++i) {
        for (int j = i; j <= k; ++j) {
            dp[0][i][j] = 1;
        }
    }
    for (int i = 3; i <= n; ++i) {
        int now=i&1;
        for (int j = 0; j <= k; ++j) {
            for (int j2=0; j2 <= k; ++j2) {
                dp[now][j][j2] = 0;
            }
        }
        for (int j2 = k; j2 >= 0; --j2) {
            for (int j=0;j<=k; ++j) {
                sum[j2][j] = dp[now^1][j][j2];
            }
            for (int j=k-1; j >= 0; --j) {
                sum[j2][j] = (sum[j2][j] + sum[j2][j+1]) % p;
            }
        }
        for (int j = 0; j <= k; ++j) {
            for (int j2 = 0; j2 <= k; ++j2) {
                int lb = max(0, j-j2);
                dp[now][j][j2] = (dp[now][j][j2] + sum[j][lb]) % p;
            }
        }
    }
    ll ans=0LL;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= i; ++j) {
            ans=(ans + dp[n&1][i][j]) % p;
        }
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

