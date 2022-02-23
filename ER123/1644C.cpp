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
#define M 202
#define N 5005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int dp1[N][N];
int dp2[N][N];
void update(int i1, int j1, int i2, int j2, int add) {
  //if (i2 == 2 && j2 == 1) cout<<"x="<<i1<<" "<<j1<<endl;
  dp1[i2][j2] = max(dp1[i2][j2], (dp1[i1][j1] < 0 ? add : dp1[i1][j1] + add));
  dp2[i2][j2] = max(dp2[i2][j2], max(dp2[i1][j1], dp1[i2][j2]));
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp1[i][j] = -1000000100;
        dp2[i][j] = -1000000100;
      }
    }
    dp1[0][0] = 0;
    dp2[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        int y = a[i+1];
        if (dp1[i][j] > -1000000100) {
          update(i, j, i+1, j+1, y+x);
          update(i, j, i+1, j, y);
        }
      }
    }
   // cout<<dp1[2][1]<<" "<<dp2[2][1]<<" "<<dp1[3][2]<<" "<<dp2[3][2]<<" "<<dp1[4][3]<<" "<<dp2[4][3]<<endl;
    for (int i = 0; i <= n; ++i) {
      int ans = dp2[n][i];
      printf("%d", ans);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
