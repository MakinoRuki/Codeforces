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
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
ll a[N];
int main() {
  scanf("%d", &n);
  ll ans=0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    ans += a[i]*(n-a[i]+1);
  }
  for (int i = 1; i < n; ++i) {
    ll l = min(a[i], a[i+1]);
    ll r = max(a[i], a[i+1]);
    ans -= (n-r+1)*l;
  }
  cout<<ans<<endl;
  return 0;
}
