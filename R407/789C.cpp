#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>n;
  for (int i =1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ll ans = abs(a[1] - a[2]);
  for (int i = 2; i < n; ++i) {
    ans = max(ans, (ll)abs(a[i]-a[i+1]));
  }
  ll tot=0LL;
  for (int i = 1; i < n; ++i) {
    if (i % 2) {
      tot += abs(a[i] - a[i+1]);
    } else {
      tot -= abs(a[i] - a[i+1]);
    }
   // if (tot == 7) cout<<"i1="<<i<<endl;
    ans = max(ans, tot);
    if (tot < 0) tot = 0;
  }
  tot = 0;
  for (int i =2 ; i < n; ++i) {
    if (i % 2) {
      tot -= abs(a[i] - a[i+1]);
    } else {
      tot += abs(a[i] - a[i+1]);
    }
  //  if (tot == 7) cout<<"i2="<<i<<endl;
    ans = max(ans ,tot);
    if (tot < 0) tot = 0;
  }
  cout<<ans<<endl;
  return 0;
}
