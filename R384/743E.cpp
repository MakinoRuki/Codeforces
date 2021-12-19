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
#define N 1002
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int a[N];
int dp[1<<9];
int id[9][N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(id, -1, sizeof(id));
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= n; ++j) {
      int cnt=0;
      for (int k = j; k <= n; ++k) {
        if (a[k] == i) {
          cnt++;
          id[i][j][cnt] = k;
        }
      }
    }
  }
  int l = 0, r = n;
  while(l < r) {
    int mid = (l+r+1)/2;
    int qq= mid/8;
    int rr=mid%8;
    bool ok=false;
    for (int i = 0; i < (1<<8); ++i) {
      int cnt=0;
      for (int j = 0; j < 8; ++j) {
        if ((1<<j) & i) cnt++;
      }
      if (cnt == rr) {
        for (int j = 0; j < (1<<8); ++j) {
          dp[j] = inf;
        }
        dp[0] = 0;
        for (int j = 0; j < (1<<8); ++j) {
          if (dp[j] < inf) {
            for (int d = 1; d <= 8; ++d) {
              if ((1<<(d-1)) & j) continue;
              int ub = qq;
              if ((1<<(d-1)) & i) ub++;
              if (ub == 0) {
                dp[j | (1<<(d-1))] = min(dp[j | (1<<(d-1))], dp[j]);
                continue;
              }
              int idx = id[d][dp[j]+1][ub];
              if (idx > dp[j] && idx <= n) {
                dp[j | (1<<(d-1))] = min(dp[j | (1<<(d-1))], idx);
              }
            }
          }
        }
        if (dp[(1<<8)-1] <= n) {
          ok=true;
          break;
        }
      }
    }
    if (ok) {
      l = mid;
    } else {
      r = mid-1;
    }
  }
  cout<<r<<endl;
  return 0;
}
