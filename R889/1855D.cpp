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
ll sum[N];
int main() {
  cin>>n;
  sum[0] = 0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = sum[i-1] + a[i];
  }
  ll ans = 0LL;
  bitset<N> b;
  b[1] = 1;
  for (int i = 1; i <= n; ++i) {
    b |= (b << a[i]);
    if (b[i]) {
      ans = max(ans, sum[i] - (i-1));
      b[i] = 0;
    }
  }
  for (int i = n+1; i <= 2*n; ++i) {
    if (b[i]) {
      ans = max(ans, sum[n] - (i-1));
    }
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

