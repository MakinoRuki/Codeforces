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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      int a,b,c,d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      int dx=abs(a-c);
      int dy=abs(b-d);
      if (d < b) {
          puts("-1");
          continue;
      }
      if (c > a + d-b) {
          puts("-1");
          continue;
      }
      int ans=d-b+(a+d-b-c);
      printf("%d\n", ans);
  }
  return 0;
}
