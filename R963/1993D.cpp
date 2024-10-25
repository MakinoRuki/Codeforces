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
bool check(int x) {
  for (int i = 0; i <= n; ++i) {
    dp[i] = -1;
  }
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if ((i%k) == 1) {
      dp[i] = (a[i] >= x);
      if (i-k>=0) dp[i] = max(dp[i], dp[i-k]);
    } else {
      dp[i] = dp[i-1] + (a[i]>=x);
      if (i-k>=0) dp[i] = max(dp[i], dp[i-k]);
    }
  }
  int r=n%k;
  if (r == 0) r = k;
  if (dp[n] >= r/2+1) return true;
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mx = max(mx, a[i]);
    }
    if (n < k) {
      sort(a+1, a+n+1);
      printf("%d\n", a[(n+1)/2]);
      continue;
    }
    int l=1,r=mx;
    while(l < r) {
      int mid = (l+r+1)/2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    printf("%d\n", r);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

