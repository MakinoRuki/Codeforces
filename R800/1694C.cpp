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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (n == 1) {
      if (a[1] == 0) {
        puts("YES");
      } else {
        puts("NO");
      }
      continue;
    }
    int id;
    for (id = n; id >= 1; --id) {
      if (a[id] != 0) break;
    }
    if (id < 1) {
      puts("YES");
      continue;
    }
    if (a[id] > 0) {
      puts("NO");
      continue;
    }
    ll x = abs(a[id]);
    int i;
    for (i = id-1; i >= 1; --i) {
      if (a[i] > x) {
        break;
      }
      x -= a[i];
      if (i > 1 && x == 0) {
        break;
      }
    }
    if (i >= 1) {
      puts("NO");
    } else {
      if (x!=0) puts("NO");
      else puts("YES");
    }
  }
  return 0;
}
