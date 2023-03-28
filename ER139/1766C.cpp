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
#define N 200005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
int a[2][N];
int dp[N][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    for (int i = 0; i < n; ++i) {
      a[0][i] = (s[i] == 'B' ? 1 : 0);
    }
    cin>>s;
    for (int i = 0; i < n; ++i) {
      a[1][i] = (s[i] == 'B' ? 1 : 0);
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 2; ++j) {
        dp[i][j] = 0;
      }
    }
    int j;
    for (j = 0; j < n; ++j) {
      if (a[0][j] || a[1][j]) {
        break;
      }
    }
    if (j >= n) {
      puts("YES");
      continue;
    }
    if (a[0][j]) dp[j][0]=1;
    if (a[1][j]) dp[j][1]=1;
    int c = -1;
    for (int i = 0; i < n-1; ++i) {
      if (dp[i][0]) {
        if (a[0][i+1] && a[1][i+1]) {
          dp[i+1][1] = 1;
        } else if (a[0][i+1]) {
          dp[i+1][0] = 1;
        }
      }
      if (dp[i][1]) {
        if (a[1][i+1] && a[0][i+1]) {
          dp[i+1][0] =1;
        } else if (a[1][i+1]) {
          dp[i+1][1] = 1;
        }
      }
      if (a[0][i] || a[1][i]) {
        c = i;
      }
    }
    if (a[0][n-1] || a[1][n-1]) c = n-1;
    if (dp[c][0] || dp[c][1]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
