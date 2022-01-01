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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, q, k;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (n == 1) {
      puts("0");
    } else {
      int ans = n-1;
      for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
          int cnt=0;
          for (int k = 1; k <= n; ++k) {
            if (k < i) {
              if ((a[j]-a[i])*(i-k) != (a[i]-a[k])*(j-i)) {
                cnt++;
              }
            } else if (k > i && k < j) {
              if ((a[j]-a[i])*(k-i) != (a[k]-a[i])*(j-i)) {
                cnt++;
              }
            } else if (k > j) {
              if ((a[j]-a[i])*(k-j) != (a[k]-a[j])*(j-i)) {
                cnt++;
              }
            }
          }
          ans = min(ans, cnt);
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
