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
#define N 100002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int m;
ll getpw(ll a, ll b) {
  ll res=1LL;
  while(b) {
    if (b&1) res=res*a%mod;
    a = a*a%mod;
    b /= 2;
  }
  return res;
}
ll cnt[N];
ll dp[N];
vector<int> ps[N];
int main() {
  cin>>m;
  for (int i = 2; i <= m; ++i) {
    ps[i].clear();
    int x = i;
    for (int j = 2; j * j <= x; ++j) {
      if (x%j==0) {
        ps[i].push_back(j);
        while(x%j==0) {
          x /= j;
        }
      }
    }
    if (x>1) ps[i].push_back(x);
  }
  ll tmp0 = getpw(m, mod-2);
  ll ans=1LL;
  dp[1] = 1LL;
  for (int i = 2; i <= m; ++i) {
    vector<int> ds;
    ds.clear();
    for (int j = 1; j * j <= i; ++j) {
      if (i%j == 0) {
        ds.push_back(j);
        if (i/j != j && i/ j != i) {
          ds.push_back(i/j);
        }
      }
    }
    dp[i] = 0LL;
    for (int j = 0; j < ds.size(); ++j) {
      int tot = m/ds[j];
      int x = i/ds[j];
      int sz = ps[x].size();
      ll sum=0LL;
      for (int k = 0; k < (1<<sz); ++k) {
        ll tmp=1LL;
        int num=0;
        for (int k2 = 0; k2 < sz; ++k2) {
          if ((1<<k2) & k) {
            tmp *= ps[x][k2];
            num++;
          }
        }
        tmp = tot/tmp;
        if (num%2==0) sum = (sum+tmp) % mod;
        else sum = (sum-tmp+mod)%mod;
      }
    //  cout<<"j="<<j<<" "<<ds[j]<<" "<<sum<<endl;
      dp[i] = (dp[ds[j]] * sum % mod * tmp0 % mod + dp[i]) % mod;
    }
    dp[i] = (dp[i] + 1) % mod;
    dp[i] = dp[i]*(ll)m % mod;
    dp[i] = dp[i] * getpw(m- m / i, mod-2) % mod;
    ans = (ans + dp[i]) % mod;
  }
  ans = ans * tmp0 % mod;
  cout<<ans<<endl;
  return 0;
}
