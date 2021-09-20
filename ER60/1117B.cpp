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
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  ll ans = 0LL;
  ll q = m/(k+1);
  ll r = m%(k+1);
  ans = q*((ll)k*(ll)a[n]+(ll)a[n-1])+r*(ll)a[n];
  cout<<ans<<endl;
  //}
  return 0;
}
