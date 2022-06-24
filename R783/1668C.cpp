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
#define N 5002
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
ll b[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ll ans = -1;
  for (int i = 1; i <= n; ++i) {
    b[i] = 0;
    ll sum=0LL;
    for (int j = i+1; j <= n; ++j) {
      ll dt = b[j-1]/a[j]+1;
      sum += dt;
      b[j] = dt * a[j];
    }
    for (int j = i-1; j >= 1; --j) {
      ll dt = abs(b[j+1])/a[j]+1;
      sum += dt;
      b[j] = -dt * a[j];
    }
    ans = (ans < 0 ? sum : min(ans, sum));
  }
  cout<<ans<<endl;
  return 0;
}
