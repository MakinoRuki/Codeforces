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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      int p1,p2,p3;
      scanf("%d%d%d", &p1, &p2, &p3);
      int ans=-1;
      for (int i = 0; i <= p3; ++i) {
          for (int j = 0; j <= p3; ++j) {
              for (int k = 0; k <= p3; ++k) {
                  if (i+j<=p1 && i+k<=p2 && j+k <= p3) {
                      int x = p1-i-j;
                      int y= p2-i-k;
                      int z=p3-j-k;
                      if (x % 2) continue;
                      if (y % 2) continue;
                      if (z % 2) continue;
                      ans = max(ans, i+j+k);
                  }
              }
          }
      }
      printf("%d\n", ans);
  }
  return 0;
}
