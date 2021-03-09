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
int n, m;
int a[N];
int sum[N];
int main() {
  cin>>n;
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = sum[i-1];
    if (a[i] == 1) {
      sum[i]++;
    }
  }
  int ans=0;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, sum[i] + (n-i)-(sum[n]-sum[i]));
  }
  for (int l = 1; l <= n; ++l) {
    int v = INT_MIN;
    for (int r = l; r <= n; ++r) {
      v = max(v, r-2*sum[r-1]);
      ans = max(ans, sum[l-1] + n-r-(sum[n]-sum[r]) + sum[r]+sum[l-1]-l+v);
    }
  }
  cout<<ans<<endl;
  return 0;
}
