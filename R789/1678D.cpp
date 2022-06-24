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
#define N 1000006
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int dp[N];
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    string s;
    cin>>s;
    for (int i = 0; i <= m; ++i) {
      cnt[i] = 0;
    }
    for (int i = 0; i <= n*m; ++i) {
      dp[i] = 0;
    }
    int rc=0, cc=0;
    int pre = -1;
    for (int i = 0; i < n*m; ++i) {
      if (s[i] == '1') {
        if (cnt[i%m]==0) {
          cnt[i%m]++;
          cc++;
        }
      }
      int res=cc;
      if (i-m>=0) {
        dp[i] = dp[i-m];
      } else {
        dp[i] = 0;
      }
      if (s[i]=='1') pre= i;
      if (pre>=0 && i-pre<m) {
        dp[i]++;
      }
      res+=dp[i];
      printf("%d", res);
      if (i <n*m-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
