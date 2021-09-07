#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b;
    scanf("%d%d", &a, &b);
    int res = 0;
    if (a % 2 == 0) {
      if ((a/2)%2) {
        res = 1;
      }
    } else {
      int a2 = a-1;
      if ((a2/2)%2) {
        res = 1;
      }
      res ^= (a-1);
    }
    if (res == b) {
      printf("%d\n", a);
    } else {
      res ^= b;
      if (res == a) {
        printf("%d\n", a+2);
      } else {
        printf("%d\n", a+1);
      }
    }
  }
  return 0;
}
