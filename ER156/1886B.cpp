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
double getds(ll ax, ll ay, ll bx, ll by) {
  return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll px, py;
    ll ax, ay;
    ll bx, by;
    scanf("%lld%lld%lld%lld%lld%lld", &px, &py, &ax, &ay, &bx, &by);
    double ans = min(max(getds(px, py, ax, ay), getds(0, 0, ax, ay)), max(getds(px, py, bx, by), getds(0, 0, bx, by)));
    ans = min(ans, max(max(getds(0, 0, ax, ay), getds(px, py, bx, by)), 0.25*getds(ax, ay, bx, by)));
    ans = min(ans, max(max(getds(0, 0, bx, by), getds(px, py, ax, ay)), 0.25*getds(ax, ay, bx, by)));
    double ans2 = (double)sqrt(ans);
    printf("%.10lf\n", ans2);
  }
  return 0;
}
