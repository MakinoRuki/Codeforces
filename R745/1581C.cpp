#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 12
#define N 500
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int d;
int a[N];
int t;
int mat[N][N];
int tot[N][N];
int val[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      for (int j = 1; j <= m; ++j) {
        mat[i][j] = s[j-1]-'0';
      }
    }
    for (int j = 1; j <= m; ++j) {
      tot[0][j] = 0;
      for (int i = 1; i <= n; ++i) {
        tot[i][j] = tot[i-1][j] + mat[i][j];
      }
    }
    int ans = inf;
    for (int i = 1; i <= n; ++i) {
      for (int i2 = i+4; i2<=n; ++i2) {
        int minv=inf;
        int sum=0;
        for (int j = 1; j <= m; ++j) {
          int s1 = (i2-1-i) - (tot[i2-1][j] - tot[i][j]);
          int s0 = tot[i2-1][j]-tot[i][j];
          if (!mat[i][j]) s0++;
          if (!mat[i2][j]) s0++;
          if (j -3 >= 1) {
            minv = min(minv, val[j-3]);
          }
          if (minv < inf) {
            ans = min(ans, sum + minv + s1);
          }
          sum += s0;
          val[j] = s1 - sum;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
