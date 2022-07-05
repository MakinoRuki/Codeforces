#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int idx[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      idx[a[i]] = i;
    }
    if (n == 1) {
      puts("1");
      continue;
    }
    int id0 = idx[0];
    int id1 = idx[1];
    int l = min(id0, id1);
    int r = max(id0, id1);
    int cnt=0;
    ll ans = 1LL;
    for (int i = 2; i < n; ++i) {
    //  cout<<"i="<<i<<" "<<l<<" "<<r<<" "<<cnt<<endl;
      if (idx[i] > l && idx[i] < r) {
        int dt = r-l+1;
        ans = (ans * (ll)(dt - i) % mod);
      } else {
        l = min(l, idx[i]);
        r = max(r, idx[i]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
