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
#define N 400005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
int a[N];
int sum[22][N];
int main() {
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i <= 20; ++i) {
    for (int j = 1; j <= 200000; ++j) {
      sum[i][j] = sum[i][j-1];
      if ((1<<i) & j) sum[i][j]++;
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &l, &r);
    int ans = r-l;
    int tot=r-l+1;
    for (int i = 0; i <= 20; ++i) {
      int det = sum[i][r] - sum[i][l-1];
      ans = min(ans, tot - det);
    }
    printf("%d\n", ans);
  }
  return 0;
}
