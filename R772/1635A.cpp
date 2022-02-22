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
#define N 200
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
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll tot=0LL;
    for (int i = 30; i >= 0; --i) {
      bool found = false;
      int j;
      for (j = 1; j <= n; ++j) {
        if ((1LL<<i) & a[j]) {
          break;
        }
      }
      if (j <= n) {
        tot += (1LL<<i);
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
