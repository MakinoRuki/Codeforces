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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
ll a, b,c,d;
int main() {
  cin>>a>>b>>c>>d;
  ll ans=0LL;
  for (ll y = b; y <= c; ++y) {
    ll l = max(c, y+a-1);
    ll r = min(d, y+b-1);
    if (l <= r) {
      ans += (l-c+1+r-c+1)*(r-l+1)/2;
    }
    l = max(y+a-1, d+1);
    if (l <= y+b-1) {
      ans += (y+b-l)*(d-c+1);
    }
    //cout<<y<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
