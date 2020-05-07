#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, p, k;
ll a[N];
int main() {
  cin>>n>>p>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  map<ll, int> cnt;
  cnt.clear();
  ll ans=0LL;
  for (int i = 1; i <= n; ++i) {
    ll res=1LL;
    for (int j = 1; j <= 4; ++j) {
      res=res*a[i]%p;
    }
    res = (res-(ll)k*a[i]%p+p) % p;
    ans += cnt[res];
    cnt[res]++;
  }
  cout<<ans<<endl;
  return 0;
}
