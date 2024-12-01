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
#define M 510
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
int a[N];
ll dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld%d", &n, &k);
    if (k == 1) {
        printf("%lld\n", n%mod);
    } else {
        dp[1] = 1;
        dp[2] = 1;
        ll id = 0;
        for (int i = 3; i < N; ++i) {
            dp[i] = (dp[i-1] + dp[i-2])%k;
            if ((dp[i] % k) == 0) {
                id = i;
                break;
            }
        }
        id %= mod;
        id = id * (n%mod) % mod;
        printf("%lld\n", id);
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

