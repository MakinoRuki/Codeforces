#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    //ll n;
    scanf("%d%d", &n, &m);
    bool ok = false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        if (i <= m) {
          ok=true;
          break;
        }
        if (n/i <= m) {
          ok=true;
          break;
        }
      }
    }
    if (n > 1 && n <= m) ok=true;
    if (ok) puts("NO");
    else puts("YES");
  }
  return 0;
}
