
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
#define N 2000005
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
int b[N];
ll dp[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i]=0;
      }
      for (int i= 1; i <= n; ++i) {
        b[a[i]]++;
      }
      vector<int> v;
      v.clear();
      for (int i = 1; i <= n; ++i) {
        if (b[i]) v.push_back(b[i]);
      }
      sort(v.begin(), v.end());
      m = (int)v.size();
      ll ans = 0LL;
      for (int i=0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
          dp[i][j] = 0LL;
        }
      }
     // cout<<"v="<<dp[1][3]<<endl;
      dp[0][0] = 1LL;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
          dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod2;
          if (j+v[i] <= n) {
            dp[i+1][j+v[i]] = (dp[i+1][j+v[i]] + dp[i][j]*(v[i]%mod2)%mod2)%mod2;
          // if (n == 2) cout<<"j="<<j<<" "<<j+v[i]<<" "<<dp[i+1][j+v[i]]<<endl;
            if (i+1 == m || j+v[i]>=v.back()) {
              ans = (ans + dp[i+1][j+v[i]]) % mod2;
            }
          //  if (n==2) cout<<"j="<<j<<" "<<dp[1][3]<<endl;
          }
        }
      }
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
