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
#define M 2000005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
ll b[N];
ll a[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n/2; ++i) {
    scanf("%lld", &b[i]);
  }
  a[1] = 0;
  a[n] = b[1]-a[1];
  for (int i = 2;  i<= n/2; ++i) {
    a[i] = max(a[i-1], b[i]-a[n+2-i]);
    a[n+1-i] = b[i] - a[i];
  }
  for (int i = 1; i <= n; ++i) {
    printf("%lld", a[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
