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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
//   cin>>t;
// //  mt19937 rnd(time(0));
//   for (int cas=1; cas<=t; ++cas) {
//     scanf("%d", &n);

//   }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    ll tot = 0LL;
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
      tot += (ll)b[i];
    }
    tot %= n;
    printf("%d\n", a[tot+1]);
  }
  return 0;
}
