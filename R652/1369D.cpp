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
#define N 2000005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,t,k;
ll dp[N];
int w[N];
int main() {
  dp[1] = 0;
  dp[2] = 0;
  for (int i =3; i <= 2000000; ++i) {
    dp[i] = (dp[i-1]+2LL*dp[i-2]%mod) % mod;
    if (i%3==0) {
      dp[i] = (dp[i]+4LL)%mod;
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    printf("%lld\n", dp[n]);
  }
  return 0;
}
