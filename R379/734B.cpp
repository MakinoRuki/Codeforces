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
#define N 400005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int main() {
  int n2,n3,n5,n6;
  cin>>n2>>n3>>n5>>n6;
  ll ans=0LL;
  for (int i = 0; i <= min(min(n2,n5),n6); ++i) {
    ll det = min(n3, n2-i);
    ans = max(ans, 32LL * det + 256LL * (ll)i);
  }
  cout<<ans<<endl;
  return 0;
}
