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
string s;
ll dx[N], dy[N];
int main() {
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  cin>>n;
  cin>>s;
  dx[0] = 0,dy[0] = 0;
  ll sx = 0, sy = 0;
  for (int i = 1; i <= n; ++i) {
    dx[i] = dx[i-1];
    dy[i] = dy[i-1];
    if (s[i-1] == 'L') dx[i]--;
    else if (s[i-1] == 'R') dx[i]++;
    else if (s[i-1] == 'U') dy[i]++;
    else dy[i]--;
  }
  ll l = 0, r = (1LL<<62)-1;
  bool ok = false;
  while(l < r) {
    ll mid = (l+r)/2;
    ll tx = mid/n*dx[n]+dx[mid%n];
    ll ty = mid/n*dy[n]+dy[mid%n];
    if (abs(c-a-tx) + abs(d-b-ty) <= mid) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  // cout<<r<<endl;
  ll tx = r/n*dx[n]+dx[r%n];
  ll ty = r/n*dy[n]+dy[r%n];
  if (abs(c-a-tx)+abs(d-b-ty)<=r) {
    cout<<r<<endl;
  } else {
    puts("-1");
  }
  return 0;
}
