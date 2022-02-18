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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N];
ll sum[N][2];
int main() {
  cin>>n;
  memset(sum, 0LL, sizeof(sum));
  for (int i= 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    sum[i][0] = sum[i-1][0];
    sum[i][1] = sum[i-1][1];
    if (i % 2) sum[i][1] += a[i];
    else sum[i][0] += a[i];
  }
  ll s0 = 0LL, s1 = 0LL;
  int ans=0;
  for (int i = n; i >= 1; --i) {
    if (sum[i-1][0] + s1 == sum[i-1][1] + s0) {
      ans++;
    }
    if (i % 2) s1 += a[i];
    else s0 += a[i];
  }
  cout<<ans<<endl;
  return 0;
}
