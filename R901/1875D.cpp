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
#define N 5010
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll dp[N];
int cnt[N];
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =0; i <= n; ++i) {
      cnt[i]=0;
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] <= n) cnt[a[i]]++;
    }
    int mex=n+1;
    for (int i = 0; i <= n; ++i) {
      if (cnt[i] == 0) {
        mex=i;
        break;
      }
    }
    if (mex==0) {
      puts("0");
      continue;
    }
    for (int i = 0; i <= n; ++i) {
      dp[i] = (1LL<<61)-1;
    }
    dp[mex]=0LL;
    for (int i = n; i >= 1; --i) {
      if (dp[i] < (1LL<<61)-1) {
        for (int j = i-1; j >= 0; --j) {
          if (cnt[j]) {
            dp[j] = min(dp[j], dp[i] + (ll)(cnt[j]-1)*(ll)i+(ll)j);
          }
        }
      }
    }
    printf("%lld\n", dp[0]);
  }
  return 0;
}
