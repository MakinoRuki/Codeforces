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
#define N 300005
#define M 2002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int getgcd(int x, int y) {
  return y == 0 ?x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int tot=0;
    for (int i = 1; i*i <= n; ++i) {
      if ((n % i) == 0) {
        int x = i;
        int j;
        int g=0;
        for (j = 1; j <= x; ++j) {
          for (int k = j; k <= n; k += x) {
            if (k > x) g = getgcd(g, abs(a[k]-a[k-x]));
          }
        }
        if (g != 1) tot++;
        if (n/i == i) continue;
        x = n/i;
        g = 0;
        for (j = 1; j <= x; ++j) {
          for (int k = j; k <= n; k += x) {
            if (k > x) g = getgcd(g, abs(a[k]-a[k-x]));
          }
        }
        if (g != 1) tot++;
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
