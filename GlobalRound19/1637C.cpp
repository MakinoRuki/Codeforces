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
#define M 202
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    bool found=false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += (ll)a[i];
      if (i > 1 && i < n) {
        if (a[i] >= 2) found=true;
      }
    }
    if (!found) {
      puts("-1");
    } else {
      if (n==3) {
        if (a[2] % 2) {
          puts("-1");
        } else {
          printf("%d\n", a[2]/2);
        }
      } else {
        // bool ev = false;
        // for (int i = 2; i < n; ++i) {
        //   if (a[i] % 2 == 0) {
        //     ev = true;
        //   }
        // }
        ll tot=0LL;
        for (int i = 2; i < n; ++i) {
          if (a[i] % 2 == 0) {
            tot += (ll)a[i]/2;
          } else {
            tot += (ll)(a[i] + 1 ) /2;
          }
        }
        printf("%lld\n", tot);
      }
    }
  }
  return 0;
}
