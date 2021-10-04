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
#define N 2000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int d;
int a[N];
int pre[N];
int sum[N];
int mp[2][N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(pre, 0, sizeof(pre));
  int ans = 0;
  for (int i = 20; i >= 0; --i) {
    sum[0] = 0;
    for (int j = 0; j < N; ++j) {
      mp[0][j] = -1;
      mp[1][j] = -1;
    }
    int bd = 0;
    mp[0][0] = 0;
    for (int j = 1; j <= n; ++j) {
      sum[j] = sum[j-1];
      if ((1<<i) & a[j]) {
        sum[j]++;
      }
      if (sum[j] % 2) {
        pre[j] |= (1<<i);
      }
      if ((1<<i)&a[j]) {
        if (mp[j%2][pre[j]] >= bd) {
          ans = max(ans, j-mp[j%2][pre[j]]);
        }
      } else {
        bd = j;
      }
      if (mp[j%2][pre[j]] < bd) {
        mp[j%2][pre[j]] = j;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
