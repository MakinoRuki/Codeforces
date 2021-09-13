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
int t, k;
ll n;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    vector<pair<ll,ll>> v;
    v.clear();
    cin>>n;
    ll p = 2;
    for (p = 2; ; p++) {
      if (p*(p-1)/2 > n) {
        break;
      }
    }
    p--;
    while(n) {
      ll x = p*(p-1)/2;
      while(x > n) {
        p--;
        x=p*(p-1)/2;
      }
      ll det = n/x;
      v.push_back(make_pair(p, det));
      n -= det * x;
    }
    string ans="";
    ans.push_back('1');
    int cnt=0;
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
      ll c1 = v[i].first;
      ll c2 = v[i].second;
      if (i > 0) c1 -= v[i-1].first;
      for (int j = 0; j < c1; ++j) {
        ans.push_back('3');
      }
      for (int j = 0; j < c2; ++j) {
        ans.push_back('7');
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
