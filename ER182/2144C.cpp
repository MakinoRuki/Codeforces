
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
ll dp[N][2];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = dp[i][1]= -1;
    }
    dp[1][0]=1;
    dp[1][1]=1;
    for (int i = 1; i<n; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (dp[i][j]>=0) {
          for (int j2 = 0; j2 < 2; ++j2) {
            int x1=a[i],y1=b[i];
            if (j) swap(x1,y1);
            int x2=a[i+1],y2=b[i+1];
            if (j2) swap(x2,y2);
          //  if (i==1 && j==0 && j2==1) cout<<"x="<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
            if ((x1<=x2) && (y1<=y2)) {
              if (dp[i+1][j2] < 0) {
                dp[i+1][j2]=0;
              }
              dp[i+1][j2] = (dp[i+1][j2] + dp[i][j]) % mod2;
            }
          }
        }
      }
    }
   // cout<<dp[2][1]<<endl;
    ll ans=(dp[n][0] + dp[n][1]) % mod2;
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
