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
#include <ctime>
#define N 1000005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int id1[N], id2[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    id1[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    id2[b[i]] = i;
  }
  ll ans = 0LL;
  int l = min(id1[1], id2[1]);
  int r = max(id1[1], id2[1]);
  if (l-1 >= 1) {
    ans += (ll)l*(ll)(l-1)/2LL;
  }
  if (r+1 <= n) {
    ans += (ll)(n-r) * (ll)(n-r+1)/2LL;
  }
  if (l+1 <= r-1) {
    ans += (ll)(r-l) * (ll)(r-l-1)/2LL;
  }
  int l1 = id1[1], r1=id1[1];
  int l2 = id2[1], r2=id2[1];
  for (int i = 2; i <= n; ++i) {
    int l = min(l1, l2);
    int r = max(r1, r2);
    if (!(id1[i] >= l && id1[i]<=r) && !(id2[i] >=l && id2[i]<=r)) {
      int lx, rx;
      if (min(id1[i], id2[i]) < l && max(id1[i],id2[i]) < l) {
        lx = max(id1[i], id2[i])+1;
        rx = n;
      } else if (min(id1[i], id2[i]) > r && max(id1[i],id2[i]) > r) {
        lx = 1;
        rx = min(id1[i], id2[i])-1;
      } else {
        lx = min(id1[i], id2[i])+1;
        rx = max(id1[i], id2[i])-1;
      }
      ans += (ll)(l-lx+1) * (ll)(rx-r+1);
    }
    l1 = min(l1, id1[i]);
    r1 = max(r1, id1[i]);
    l2 = min(l2, id2[i]);
    r2 = max(r2, id2[i]);
  }
  ans++;
  cout<<ans<<endl;
  return 0;
}
