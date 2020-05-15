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
#define N 1000005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int dp[N];
int cnt[N];
string s;
int main() {
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    cin>>s;
    int tot=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') tot++;
    }
    for (int i = 1; i <= n+1; ++i) {
      cnt[i] = 0;
    }
    int ans=tot;
    for (int i = n; i >= 1; --i) {
      if (i + k > n) {
        cnt[i] = (s[i-1] == '1' ? 1 : 0);
        dp[i] = (s[i-1]=='1' ? 0 : 1);
      } else {
        int det = (s[i-1]=='1' ? 0 : 1);
        cnt[i] = (cnt[i+k] + (s[i-1]=='1' ? 1: 0));
        dp[i] = min(dp[i+k]+det, cnt[i+k]+det);
      }
      ans = min(ans, dp[i]+tot-cnt[i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
