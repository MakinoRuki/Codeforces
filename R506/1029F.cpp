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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int main() {
  ll a,b;
  cin>>a>>b;
  vector<pair<ll, ll>> da, db;
  da.clear();
  db.clear();
  for (ll i = 1; i * i <= a; ++i) {
    if (a % i == 0) {
      da.push_back(make_pair(i, a/i));
    }
  }
  for (ll i = 1; i * i <= b; ++i) {
    if (b % i == 0) {
      db.push_back(make_pair(i, b/i));
    }
  }
  set<ll> sa, sb;
  sa.clear();
  sb.clear();
  ll ans = -1;
  int i = 0, j = 0;
  for (ll x = 1; x * x <= (a+b); ++x) {
    if ((a+b)% x == 0) {
      ll y = (a+b)/x;
      while(i < da.size() && da[i].first <= x) {
        sa.insert(da[i].second);
        i++;
      }
      while(j < db.size() && db[j].first <= x) {
        sb.insert(db[j].second);
        j++;
      }
      if ((!sa.empty() && (*sa.begin()) <= y) || (!sb.empty() && (*sb.begin()) <= y)) {
        if (ans < 0 || ans > (x+y)*2) {
          ans = (x+y)*2;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
