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
const ll mod2 = 998244353LL;
int n, m, k;
int t;
ll a[N];
int main() {
  cin>>n>>k;
  for (int i =1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  deque<pair<int, ll>> dq;
  ll ans = 0LL;
  ll det = 0LL;
  ll sum = 0LL;
  ll tot=0LL;
  for (int i = n; i >= k; --i) {
    while(!dq.empty() && dq.front().first > i) {
      sum -= dq.front().second * k;
      tot -= dq.front().second;
      det -= dq.front().second * k;
      dq.pop_front();
    }
    ll z = sum - det;
    ll x = max(0LL, a[i] - z);
  //  cout<<"i="<<i<<" "<<sum<<" "<<det<<endl;
    if (x > 0) {
    //  cout<<"i="<<i<<" "<<x<<endl;
      ll y = (x+k-1)/k;
      ans += y;
      dq.push_back(make_pair(i-k+1, y));
      sum += k * y;
      tot += y;
    }
    det += tot;
  }
 // cout<<ans<<endl;
  ll mx = 0LL;
  for (int i = k-1; i >= 1; --i) {
    while(!dq.empty() && dq.front().first > i) {
      sum -= dq.front().second * k;
      tot -= dq.front().second;
      det -= dq.front().second * k;
      dq.pop_front();
    }
    ll x = max(0LL, a[i] - (sum-det));
  //  cout<<"i="<<i<<" "<<sum<<" "<<det<<endl;
    if (x > 0) {
      mx = max(mx, (x+i-1)/i);
    }
    det += tot;
  }
  ans += mx;
  printf("%lld\n", ans);
  return 0;
}
