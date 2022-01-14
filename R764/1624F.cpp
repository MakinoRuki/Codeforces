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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q, k;
int t;
int a[N];
int main() {
  scanf("%d", &n);
  int l = 1, r = n;
  int cur = 0;
  while(l < r) {
    int mid = (l+r+1)/2;
    int det = n-(mid+cur)%n;
    printf("+ %d\n", det);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    cur += det;
    if (x >= (mid+det+cur)/n) {
      l = mid;
    } else {
      r = mid-1;
    }
  }
  printf("! %d\n",cur+r);
  fflush(stdout);
  return 0;
}
