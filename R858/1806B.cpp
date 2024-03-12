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
#define N 500005
#define M 15
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
      scanf("%d", &n);
      int n0=0;
      int mx=0;
      for (int i= 1; i <= n; ++i) {
          scanf("%d", &a[i]);
          if (a[i] == 0) {
              n0++;
          }
          mx=max(mx, a[i]);
      }
      if (n0 <= (n+1)/2) {
          puts("0");
          continue;
      }
      if (mx == 1) {
          puts("2");
      } else {
          puts("1");
      }
  }
  return 0;
}
