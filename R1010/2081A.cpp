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
#define N 600005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int cnt[N];
ll dp[N][2];
ll getpw(ll x, ll y) {
    ll res=1LL;
    while(y) {
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    reverse(s.begin(), s.end());
    if (n == 1) {
        puts("0");
        continue;
    }
    // 不能从前往后dp期望。期望步数是在最后才确定。
    // 可以记忆化搜，dp[cur]=(dp[next]+1)*P(cur)。而不是dp[next]=(dp[cur]+1)*P(next)。
    dp[0][0] = 1LL;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = 0;
        dp[i][1] = 0;
        if (s[i-1] == '0') {
            dp[i][0] = (dp[i][0] + dp[i-1][0])%mod;
            dp[i][0] = (dp[i][0] + dp[i-1][1]*getpw(2, mod-2)%mod) % mod;
            dp[i][1] = dp[i-1][1]*getpw(2, mod-2)%mod;
        } else {
            dp[i][0] = dp[i-1][0]*getpw(2, mod-2)%mod;
            dp[i][1] = (dp[i][1] + dp[i-1][1]) % mod;
            dp[i][1] = (dp[i][1] + dp[i-1][0]*getpw(2, mod-2)%mod) % mod;
        }
    }
    ll ans = (dp[n-1][0]*(n-1)%mod + dp[n-1][1]*n%mod) % mod;
    printf("%lld\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
