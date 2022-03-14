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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll l, r;
    r = d - a[n];
    set<pair<int,int>> ss;
    ss.clear();
    ss.insert(make_pair(a[1] - 1, 0));
    for (int i = 1; i < n; ++i) {
      ss.insert(make_pair(a[i+1] - a[i] - 1, i));
    }
    ll ans = (*ss.begin()).first;
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        ss.erase(make_pair(a[1] - 1, 0));
        ss.erase(make_pair(a[2] - a[1] - 1, 1));
        ss.insert(make_pair(a[2] - 1, 0));
      } else if (i == n) {
        ss.erase(make_pair(a[n] - a[n-1] - 1, n-1));
        r = d - a[n-1];
      } else {
        ss.erase(make_pair(a[i] - a[i-1] - 1, i-1));
        ss.erase(make_pair(a[i+1] - a[i] - 1, i));
        ss.insert(make_pair(a[i+1] - a[i-1] - 1, i-1));
      }
      if (ss.size() == 1) {
        ll det = (*ss.begin()).first;
        if (det > 0) {
          ans = max(ans, (det-1)/2);
          if (r > 0) ans = max(ans, min(det, r-1));
        } else {
          ans = max(ans, 0LL);
        }
      } else if (ss.size() >= 2) {
        ll det1 = (*ss.rbegin()).first;
        ll det2 = (*ss.begin()).first;
        if (det1 > 0) {
          ans = max(ans, min(det2, (det1-1)/2));
        }
        if (r > 0) {
          ans = max(ans, min(det2, r-1));
        }
      }
      if (i == 1) {
        ss.erase(make_pair(a[2] - 1, 0));
        ss.insert(make_pair(a[1] - 1, 0));
        ss.insert(make_pair(a[2] - a[1] - 1, 1)); 
      } else if (i == n) {
        ss.insert(make_pair(a[n] - a[n-1] - 1, n-1));
        r = d - a[n];
      } else {
        ss.erase(make_pair(a[i+1] - a[i-1] - 1, i-1));
        ss.insert(make_pair(a[i] - a[i-1] - 1, i-1));
        ss.insert(make_pair(a[i+1] - a[i] - 1, i));
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
