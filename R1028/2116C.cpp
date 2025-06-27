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
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
ll x;
int t;
int a[N];
int dp[2][M];
int gg[M][M];
int getgcd(int x, int y) {
    if (gg[x][y] >= 0) return gg[x][y];
    if (gg[y][x] >= 0) return gg[y][x];
    return y == 0 ? x : getgcd(y ,x%y);
}
int main() {
  memset(gg, -1, sizeof(gg));
  for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
          gg[i][j] = getgcd(i, j);
      }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int ag = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ag = getgcd(ag, a[i]);
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == ag) cnt++;
    }
    if (cnt > 0) {
        printf("%d\n", n-cnt);
        continue;
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int now=i&1;
        for (int j = 0; j < M; ++j) {
            dp[now^1][j] = inf;
        }
        dp[now^1][a[i+1]] = 0;
        for (int j = 0; j < M; ++j) {
            if (dp[now][j] < inf) {
                dp[now^1][j] = min(dp[now^1][j], dp[now][j]);
                int ng = gg[j][a[i+1]];
                dp[now^1][ng] = min(dp[now^1][ng], dp[now][j]+1);
            }
        }
    }
    int res=dp[n&1][ag] + n-1;
    printf("%d\n", res);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
