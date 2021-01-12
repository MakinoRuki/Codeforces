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
int n;
ll t;
ll sum[N];
ll a[N];
int main() {
  cin>>n>>t;
  ll tot=0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    tot += a[i];
  }
  ll ans=0LL;
  while(true) {
    int cnt=0;
    ll sum=0LL;
    for (int i = 1; i <= n; ++i) {
      if (t >= a[i]) {
        t -= a[i];
        sum += a[i];
        cnt++;
      }
    }
    if (cnt == 0) break;
    ans += cnt;
    ans += t/sum*cnt;
    t %= sum;
  }
  cout<<ans<<endl;
  return 0;
}
