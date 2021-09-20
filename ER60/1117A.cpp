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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int a[N];
int main() {
 // for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    double ans = (double)a[1];
    int id1 = 1;
    int len1 = 1;
    double sum = (double)a[1];
    int id2 = 1, len2 = 1;
    for (int i = 2; i <= n; ++i) {
      if ((double)a[i] * (double)len1 > sum) {
        sum = a[i];
        id1 = i;
        len1 = 1;
      } else {
        sum += (double)a[i];
        len1++;
      }
      if (sum > (double)len1 * ans) {
        ans = sum/(double)len1;
        len2 = len1;
        id2 = id1;
      } else if (sum == (double)len1*ans && len1 > len2) {
        len2 = len1;
        id2 = id1;
      }
    }
    printf("%d\n", len2);
  //}
  return 0;
}
