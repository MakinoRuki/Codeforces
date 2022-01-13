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
int n, m, q, k;
int a[N];
ll b[N];
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int l = 0, r = 1000000000;
    while(l < r) {
      int mid = (l+r+1)/2;
      for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
      }
      bool ok = true;
      for (int i = n; i >= 3; --i) {
        if (b[i] - mid < 0) {
          ok=false;
          break;
        }
        ll det = min((ll)a[i], b[i]-mid) / 3;
        b[i] -= 3*det;
        b[i-1] += det;
        b[i-2] += 2*det;
      }
      for (int i = 1; i <= n; ++i) {
        if (b[i] < mid) {
          ok=false;
          break;
        }
      }
      if (!ok) {
        r = mid-1;
      } else {
        l = mid;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
