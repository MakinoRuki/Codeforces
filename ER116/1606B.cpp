#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, m, h;
ll k, n;
int q;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld%lld", &n, &k);
    if (n == 1) {
      puts("0");
    } else {
      ll i;
      ll tot = n;
      for (i = 1; i <= 60; ++i) {
        if ((1LL<<(i-1)) > k) {
          break;
        }
        tot = (1LL<<i);
        if (tot >= n) break;
      }
      if (tot >= n) {
        printf("%lld\n", i);
      } else {
        i--;
        i += (n-tot+k-1)/k;
        printf("%lld\n", i);
      }
    }
  }
  return 0;
}
