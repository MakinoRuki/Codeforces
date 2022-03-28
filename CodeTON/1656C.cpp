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
#include <ctime>
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int c;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    bool f1 = false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == 1) {
        f1 = true;
      }
    }
    if (n == 1 || !f1) {
      puts("YES");
    } else {
      sort(a+1, a+n+1);
      bool ok = true;
      for (int i= 1; i < n; ++i) {
        if (a[i] + 1 == a[i+1]) {
          ok=false;
          break;
        }
      }
      if (ok) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}
