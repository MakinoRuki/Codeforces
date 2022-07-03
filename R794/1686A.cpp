#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
      int sum=0;
      for (int j = 1; j <= n; ++j) {
        if (i != j) sum += a[j];
      }
      if ((sum % (n-1) == 0) && (sum / (n-1) == a[i])) {
        ok=true;
        break;
      }
    }
    if(ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
