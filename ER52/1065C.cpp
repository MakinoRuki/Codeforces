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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll k;
int h[N];
int hn[N];
ll sum[N];
ll dp[N];
int main() {
  cin>>n>>k;
  memset(hn, 0, sizeof(hn));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
    hn[h[i]]++;
  }
  for (int i = 200000; i >= 1; --i) {
    hn[i] += hn[i+1];
  }
  memset(sum, 0LL, sizeof(sum));
  for (int i = 1; i <= 200000; ++i) {
    sum[i] = sum[i-1] + (ll)hn[i];
  }
  memset(dp, 0LL, sizeof(dp));
  for (int i = 200000; i >= 1; --i) {
    if (i == 200000) continue;
    int l = i+1,r = 200000;
    while(l < r) {
      int mid=(l+r+1)/2;
      if (sum[mid] - sum[i] <= k) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    if (sum[r]-sum[i] > 0) dp[i] = dp[r]+1;
    //if (i <= 4) cout<<i<<" "<<r<<" "<<dp[r]<<" "<<dp[i]<<endl;
  }
  sort(h+1, h+n+1);
  cout<<dp[h[1]]<<endl;
  return 0;
}
