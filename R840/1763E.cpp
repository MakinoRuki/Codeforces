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
#define N 500005
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
int n, m, k, q;
int t;
int a[N];
int dp[N];
int main() {
  int p;
  cin>>p;
  dp[0] = 0LL;
  for (int i = 1; i <= p; ++i) {
    dp[i] = inf;
    for (int x = 1; x * (x-1)/2 <= i; ++x) {
      dp[i] = min(dp[i], dp[i-x*(x-1)/2] + x);
    }
  }
  ll u = (ll)dp[p] * (ll)(dp[p]-1) / 2LL - p;
  printf("%d %lld\n", dp[p], u);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

