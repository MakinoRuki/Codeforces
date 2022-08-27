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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int p[N];
// int p2[N];
// ll getgcd(ll x, ll y) {
//   return y == 0 ? x : getgcd(y, x%y);
// }
// ll getlcm(ll x, ll y) {
//   return x / getgcd(x, y) * y;
// }
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
  //  ll tot=0LL;
    if (n%2) {
      p[1] = 1;
     // tot++;
      for (int i = 2; i <= n; i += 2) {
        p[i] = i+1;
        p[i+1] = i;
       // tot += 2LL * (ll)i * (ll)(i+1);
      }
    } else {
      for (int i = 1; i <= n; i += 2) {
        p[i] = i+1;
        p[i+1] = i;
       // tot += 2LL * (ll)i * (ll)(i+1);
      }
    }
  //  printf("%lld\n", tot);
    for (int i = 1; i <= n; ++i) {
      printf("%d", p[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  // cin>>n;
  // for (int i = 1; i <= n; ++i) {
  //   p[i] = i;
  // }
  // ll mx = 0LL;
  // do {
  //   ll tot=0LL;
  //   for (int i = 1; i <= n; ++i) {
  //     tot += getlcm(i, p[i]);
  //   }
  //   if (tot > mx) {
  //     mx = tot;
  //     for (int i = 1; i <= n; ++i) {
  //       p2[i] = p[i];
  //     }
  //   }
  // } while(next_permutation(p+1, p+n+1));
  // cout<<mx<<endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout<<p2[i]<<" ";
  // }
  // cout<<endl;
  return 0;
}
