#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
bool dp1[N][N];
int dp2[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      dp2[i] = 0;
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        dp1[i][j] = false;
      }
      for (int j = 1; j <= n; ++j) {
        cnt[j] = 0;
      }
      int mx = 0;
      for (int j = i; j <= n; ++j) {
        cnt[a[j]]++;
        mx = max(mx, cnt[a[j]]);
        int len = j-i+1;
        if (len % 2 == 0 && mx <= len/2) {
          dp1[i][j] = true;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i-1 <= 0 || dp1[1][i-1]) {
        dp2[i] = 1;
      }
      for (int j = 1; j < i; ++j) {
        if (a[j] == a[i] && dp2[j] > 0 && (j+1>i-1 || dp1[j+1][i-1])) {
          dp2[i] = max(dp2[i], dp2[j]+1);
        }
      }
      if (i+1>n || dp1[i+1][n]) {
       // if (dp2[i]>0) cout<<"i="<<i<<" "<<dp2[i]<<endl;
        ans=max(ans, dp2[i]);
      }
     // cout<<"i="<<i<<" "<<dp2[i]<<endl;
    }
    printf("%d\n", ans);
  }
  return 0;
}
