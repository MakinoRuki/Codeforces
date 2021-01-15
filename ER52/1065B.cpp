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
#define M 21
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t;
ll m;
int main() {
  cin>>n>>m;
  ll minv = max(0LL, n-2*m);
  ll maxv = 0;
  if (m > 0) {
    for (int i = 1; i <= n; ++i) {
      ll cur = (ll)i*(ll)(i-1)/2;
      if (m <= cur) {
        maxv = n-i;
        break;
      }
    }
  } else {
    maxv = n;
  }
  cout<<minv<<" "<<maxv<<endl;
  return 0;
}
