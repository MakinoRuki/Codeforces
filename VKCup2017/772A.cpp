/* 二分(-1的条件). 能无限的条件：充得比放得快 */ 

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
#include <stack>
#include <bitset>
#include <chrono>
#define N 1000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);

  // }
  ll p;
  cin>>n>>p;
  ll sum=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    sum += a[i];
  }
  // 能无限的条件就是单位时间消耗多少就能补上多少。
  if (sum <= p) {
    puts("-1");
    return 0;
  }
  // 卡精度！！要用long double啊啊啊！！
  long double l = 0.0, r = 1e18;
  // limit accuracy of binary search.
  for (int i =1; i <= 200; ++i) {
    long double mid = (l+r) * 0.5;
    long double tot=0.0;
    for (int j = 1; j <= n; ++j) {
      tot += max((long double)0.0, mid * a[j] - b[j]);
    }
    if (tot <= mid * p) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (r >= 1e18) puts("-1");
  else printf("%.10Lf\n", r);
  return 0;
}
 
