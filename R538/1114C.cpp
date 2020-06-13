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
#define M 100005
#define inf 1000000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
ll n, b;
int main() {
  cin>>n>>b;
  vector<pair<ll, ll>> ps;
  ps.clear();
  for (ll i = 2; i*i <= b; ++i) {
    if (b%i==0) {
      int cnt=0;
      while(b%i==0) {
        cnt++;
        b/=i;
      }
      ps.push_back(make_pair(i, cnt));
    }
  }
  if (b>1) ps.push_back(make_pair(b, 1));
  ll ans=(1LL<<61);
  for (int i = 0; i < ps.size(); ++i) {
    ll cnt=0;
    ll x = n;
    while(x) {
      cnt += x/ps[i].first;
      x /= ps[i].first;
    }
    ans = min(ans, cnt/ps[i].second);
  }
  cout<<ans<<endl;
  return 0;
}
