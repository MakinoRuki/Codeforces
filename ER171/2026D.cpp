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
#define N 300005
#define M 2010
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
ll sum0[N];
ll sum[N];
ll dp[N];
ll cnt[N];
ll cal(ll x) {
    if (x <= 0) return 0LL;
    ll tot=0LL;
    ll l = 0, r = n;
    while(l < r) {
        int mid=(l+r+1)/2;
        if (cnt[mid] <= x) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
    ll res = dp[r];
    ll dt = x - cnt[r];
    int id = r+1;
    int id2 = id+dt-1;
    res += sum[id2]-sum[r] - sum0[r]*dt;
    return res;
}
int main() {
 // cin>>t;
 // for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) {
          scanf("%d", &a[i]);
      }
      sum[0] = 0LL;
      for (int i = 1; i <= n; ++i) {
          sum[i] = sum[i-1] + a[i];
          sum0[i] = sum[i];
      }
      for (int i = 1; i <= n; ++i) {
          sum[i] += sum[i-1];
      }
      dp[1] = sum[n];
      for (int i = 2; i <= n; ++i) {
          dp[i] = dp[i-1] - (ll)a[i-1]*(ll)(n+1-(i-1));
         // cout<<"i0="<<i<<" "<<dp[i]<<endl;
      }
      for (int i = 1; i <= n; ++i) {
          dp[i] += dp[i-1];
         // cout<<"i="<<i<<" "<<dp[i]<<endl;
      }
      cnt[1] = n;
      for (int i = 2; i <= n; ++i) {
          cnt[i] = cnt[i-1] + (n+1)-i;
      }
      scanf("%d", &q);
      while(q-->0) {
          ll l, r;
          scanf("%lld%lld", &l, &r);
          ll ans = cal(r) - cal(l-1);
          printf("%lld\n", ans);
      }
 // }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

