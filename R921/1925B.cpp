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
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &x, &n);
    int ans=0;
    for (int g = 1; g*g <= x; ++g) {
      if ((x%g)==0) {
        if (x/g >= n) ans=max(ans, g);
        if (x/g != g) {
          if (g >= n) ans=max(ans, x/g);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
