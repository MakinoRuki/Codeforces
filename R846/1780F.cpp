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
#define N 300005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
ll sum[N];
ll dp[N];
int main() {
  memset(sum, 0, sizeof(sum));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[a[i]]++;
  }
  for (int i = 1; i < N; ++i) {
    sum[i] += sum[i-1];
  }
  memset(dp, 0LL, sizeof(dp));
  ll ans=(ll)n*(ll)(n-1)*(ll)(n-2)/6LL;
  for (int g = N-1; g >= 2; --g) {
    vector<int> ps;
    ps.clear();
    for (int i = g; i < N; i += g) {
      if (sum[i] - sum[i-1]) {
        ps.push_back(i);
      }
    }
    ll tot=(ll)ps.size();
    for (int i = 1; i < ps.size(); ++i) {
      int l = ps[i-1], r = ps[i];
     // if (g == 2) cout<<"i="<<i<<" "<<l<<" "<<r<<" "<<sum[r-1]-sum[l]<<endl;
      if (r-1>=l+1 && sum[r-1]-sum[l]>0) {
        ll tmp = (ll)(sum[r-1]-sum[l]) * (ll)i * (tot-i);
        dp[g] += tmp;
      }
    }
    if (tot >= 3) {
      dp[g] += tot * (tot-1) * (tot-2) / 6LL;
    }
    for (int i = 2 * g; i < N; i += g) {
      dp[g] -= dp[i];
    }
    //if (g <= 16) cout<<"g="<<g<<" "<<dp[g]<<endl;
    ans -= dp[g];
  }
  printf("%lld\n", ans);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

