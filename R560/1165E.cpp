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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
int a[N], b[N];
int main() {
  scanf("%d", &n);
  vector<ll> rk1;
  vector<ll> rk2;
  rk1.clear();
  rk2.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    rk1.push_back((ll)i*(ll)(n-i+1)*(ll)a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    rk2.push_back((ll)b[i]);
  }
  sort(rk1.begin(), rk1.end());
  reverse(rk1.begin(), rk1.end());
  sort(rk2.begin(), rk2.end());
  ll ans = 0LL;
  for (int i = 0; i < n; ++i) {
    ans = (ans + rk1[i]%mod * (rk2[i]%mod) % mod) % mod;
  }
  cout<<ans<<endl;
  return 0;
}
