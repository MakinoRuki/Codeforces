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
#define M 202
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
int a[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    scanf("%d", &n);
    if (n % 2) {
      puts("0");
    } else {
      n /= 2;
      ll ans = 1LL;
      for (int i = 1; i <= n; ++i) {
        ans = ans * (ll)i % mod2;
      }
      for (int i = 1; i <= n; ++i) {
        ans = ans * (ll)i % mod2;
      }
      printf("%lld\n", ans);
    }

  }
  // cin>>n;
  // for (int i = 1; i <= n; ++i) {
  //   a[i] = i;
  // }
  // do {
  //   int g = a[1];
  //   for (int i = 2; i <= n; ++i) {
  //     g = getgcd(g, i * a[i]);
  //   }
  //   if (g > 1) {
  //     for (int i =1; i <= n; ++i) {
  //       cout<<a[i]<<" ";
  //     }
  //     cout<<endl;
  //   }
  // } while(next_permutation(a+1, a+n+1));
  return 0;
}
