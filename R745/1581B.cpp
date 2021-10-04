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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int d;
int a[N];
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    ll det = (ll)n*(ll)(n-1)/2;
    if (m > det) {
      puts("NO");
      continue;
    }
    if (k >= 4) {
      if (m >= n-1) puts("YES");
      else puts("NO");
    } else if (k == 3) {
      ll det = (ll)n*(ll)(n-1)/2;
      if (m < det) puts("NO");
      else puts("YES");
    } else if (k == 2) {
      if (n <= 1) puts("YES");
      else puts("NO");
    } else {
      puts("NO");
    }
  }
  return 0;
}
