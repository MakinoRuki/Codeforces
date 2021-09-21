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
#define N 50002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, v, k;
int a[N];
int main() {
  cin>>n;
  int tot=0;
  int ans=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    tot += a[i];
  }
  ans=tot;
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j <= a[i]; ++j) {
      if (a[i] % j) continue;
      int tot2 = tot - a[i];
      if (i == 1) {
        tot2 -= a[2];
        tot2 += a[i] / j + a[2]*j;
      } else {
        tot2 -= a[1];
        tot2 += a[i] / j + a[1] * j;
      }
     // if (tot2 == 13) cout<<i<<" "<<j<<endl;
      ans = min(ans, tot2);
    }
  }
  cout<<ans<<endl;
  return 0;
}
