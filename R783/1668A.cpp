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
#define N 100005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    if (n <= 1 || m <= 1) {
      ll dt = n-1+m-1;
      if (dt <= 1) {
        printf("%lld\n", dt);
      } else {
        puts("-1");
      }
    } else {
      ll dt = n-1+m-1;
      ll dt2 = max(n-1, m-1)-min(n-1, m-1);
      if (dt % 2) {
        printf("%lld\n", dt2-1+dt);
      } else {
        printf("%lld\n", dt2+dt);
      }
    }
  }
  return 0;
}
