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
ll sum[N];
int dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sum[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + a[i];
    }
    map<ll, int> idx;
    idx.clear();
    idx[0] = 0;
    dp[0] = 0;
    int ans=0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        if (idx.find(sum[i]) != idx.end()) {
            int j = idx[sum[i]];
            dp[i] = max(dp[i], dp[j]+1);
        }
        dp[i] = max(dp[i], dp[i-1]);
        ans = max(ans, dp[i]);
       // else ans = max(ans, dp[i]-1);
        idx[sum[i]] = i;
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

