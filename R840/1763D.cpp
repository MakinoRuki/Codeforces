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
#define M 110
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
ll comb[M][M];
ll calc(int x, int y) {
  if (x < 0) return 0;
  if (y < 0) return 0;
  if (x < y) return 0;
  return comb[x][y];
}
int main() {
  memset(comb, 0LL, sizeof(comb));
  comb[0][0] = 1LL;
  for (int i = 1; i <= 100; ++i) {
    comb[i][0] = 1LL;
    for (int j = 1; j <= i; ++j) {
      comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int i,j,x,y;
    scanf("%d%d%d%d%d", &n, &i, &j, &x, &y);
    ll ans = 0LL;
    if (x < y) {
      if (y == n) {
        if (j != n) ans = (ans + calc(x-1,i-1)*calc(y-x-1,j-i-1)%mod)%mod;
      } else {
        for (int p = j+1; p < n; ++p) {
          ans = (ans + calc(x-1,i-1)*calc(y-x-1,j-i-1)%mod*calc(n-y-1,p-j-1)%mod)%mod;
        }
        for (int p = i+1; p < j; ++p) {
          ans = (ans + calc(x-1,i-1)*calc(n-y-1,j-p-1)%mod*calc(y-x-1,j+y-n-i-1)%mod)%mod;
        }
      }
    } else {
      if (x == n) {
        if (i != 1) ans = (ans + calc(y-1, n-j) * calc(x-y-1, j-i-1) % mod) % mod;
      } else {
        for (int p = 2; p < i; ++p) {
          ans = (ans + calc(y-1, n-j) * calc(x-y-1, j-i-1)%mod * calc(n-x-1, i-p-1) % mod) % mod;
        }
        for (int p = i; p < j; ++p) {
          ans = (ans + calc(y-1, n-j) * calc(n-x-1, p-i-1) % mod * calc(x-y-1, j-1-n+x-i) % mod) % mod;
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

