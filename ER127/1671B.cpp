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
#include <list>
#include <random>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
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
    for (int st = a[1] - 1; st <= a[1] + 1; ++st) {
      int pre = st;
      int i;
      for (i = 2; i <= n; ++i) {
        if (pre+1 == a[i] - 1 || pre+1 == a[i] || pre+1 == a[i]+1) {
          pre++;
        } else {
          break;
        }
      }
      if (i > n) {
        ok = true;
        break;
      }
    }
    if (ok) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
