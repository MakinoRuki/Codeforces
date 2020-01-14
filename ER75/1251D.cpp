#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
int t,n;
ll s;
vector<pair<ll, ll>> lr;
int check(ll m) {
  int cnt1=0;
  int cnt2=0;
  for (int i = 0; i < n; ++i) {
    if (lr[i].second < m) cnt1++;
    else if (lr[i].first > m) cnt2++;
  }
  if (n-cnt1 < (n+1)/2) return 1;
  if (cnt2 > n/2) return -1;
  vector<ll> tmp;
  tmp.clear();
  ll sum= 0;
  for (int i = 0; i < n; ++i) {
    if (lr[i].first <= m && lr[i].second >= m) {
      tmp.push_back(lr[i].first);
    } else {
      sum += lr[i].first;
    }
  }
  sort(tmp.begin(), tmp.end());
  for (int i = cnt1+1; i <= n/2; ++i) {
    sum += tmp[i-cnt1-1];
  }
  sum += (ll)((n+1)/2 - cnt2) * m;
  return (sum <= s ? 0 : 1);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>s;
    lr.clear();
    for (int i = 0; i < n; ++i) {
      ll l, r;
      cin>>l>>r;
      lr.push_back(make_pair(l, r));
    }
    ll l = 0, r= s;
    while(l < r) {
      ll m = (l+r+1)/2LL;
      int res=check(m);
      if (res < 0) l = m+1;
      else if (res > 0) r = m-1;
      else l = m;
    }
    cout<<r<<endl;
  }
	return 0;
}
