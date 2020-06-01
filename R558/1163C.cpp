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
const ll mod = 1000000007LL;
int n;
ll x[N], y[N];
ll getgcd(ll a, ll b) {
  return b==0? a : getgcd(b, a%b);
}
int main() {
  cin>>n;
  set<pair<pair<int,int>, pair<ll, ll>>> mp;
  mp.clear();
  for (int i = 0; i < n; ++i) {
    //ll x,y;
    scanf("%lld%lld", &x[i],&y[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      ll dx=x[j]-x[i];
      ll dy=y[j]-y[i];
      if (dx<0&&dy<0) {
        dx=-dx;
        dy=-dy;
      }
      ll d = getgcd(dx, dy);
      dx/=d;
      dy/=d;
      pair<ll, ll> c;
      if (dx==0) {
        c=make_pair(x[i], 0);
      } else {
        c=make_pair(y[i]*dx-x[i]*dy, dx);
      }
      mp.insert(make_pair(make_pair(dx, dy), c));
    }
  }
  ll ans=0LL;
  ll sum=mp.size();
 // cout<<"sum="<<sum<<endl;
  map<pair<int, int>, ll> mp2;
  mp2.clear();
  vector<pair<pair<int,int>, pair<ll, ll>>> mv(mp.begin(), mp.end());
  for (int i = 0; i < mv.size(); ++i) {
    mp2[mv[i].first]++;
  }
  for (auto itr = mp2.begin(); itr != mp2.end(); ++itr) {
    ans += itr->second * (sum-itr->second);
  }
  cout<<ans/2<<endl;
  return 0;
}
