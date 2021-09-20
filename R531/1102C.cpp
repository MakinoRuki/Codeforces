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
#define M 12
#define N 10000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, x, y;
int a[N];
int main() {
  cin>>n>>x>>y;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  if (x > y) {
    printf("%d\n", n);
  } else {
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (x >= a[i]) {
        cnt++;
      }
    }
    printf("%d\n", (cnt+1)/2);
  }
  return 0;
}
