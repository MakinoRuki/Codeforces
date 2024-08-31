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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
ll sum[N];
ll dp[2][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i <= 100000; ++i) {
      cnt[i]=0;
      sum[i]=0;
      dp[0][i]=dp[1][i]=0;
    }
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    for (int i = 100000; i >= 1; --i) {
      sum[i] = sum[i+1] + cnt[i+1];
    }
   // cout<<sum[2]<<" "<<sum[3]<<" "<<sum[6]<<" "<<sum[12]<<" "<<sum[17]<<endl;
    vector<int> v;
    for (int g = 1; g <= 100000; g++) {
      v.clear();
      for (int i = g; i <= 100000; i += g) {
        if (cnt[i]>0) v.push_back(i);
      }
      ll tot=0LL;
      for (int i = 0; i < v.size(); ++i) {
        int x=v[i];
        ll y=cnt[x];
        if (cnt[x] >= 3) {
          dp[0][g] += y*(y-1)*(y-2)/6LL;
        }
        if (y>=2) {
          dp[0][g] += tot*(y*(y-1)/2LL);
          dp[0][g] += (y*(y-1)/2LL)*sum[x];
        }
       // if (g==2) cout<<"i="<<i<<" "<<x<<" "<<y<<" "<<tot<<" "<<sum[x]<<endl;
        dp[0][g] += y*tot*sum[x];
        tot += cnt[x];
      }
    }
   // cout<<dp[0][2]<<" "<<dp[0][3]<<" "<<dp[0][6]<<endl;
    for (int i = 100000; i >= 1; --i) {
      dp[1][i] = dp[0][i];
      for (int j = i*2; j <= 100000; j += i) {
        dp[1][i] -= dp[1][j];
      }
    }
    ll ans=0LL;
    for (int i = 1; i <= 100000; ++i) {
      ans += (ll)i * dp[1][i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
