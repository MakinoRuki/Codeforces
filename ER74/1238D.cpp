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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int p[N];
int main() {
  cin>>n;
  string s;
  cin>>s;
  ll ans = ((ll)n * (ll)(n+1))/2;
  ans -= n;
  vector<int> sgs;
  sgs.clear();
  int cnt=0;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || s[i] == s[i-1]) {
      cnt++;
    } else {
      sgs.push_back(cnt);
      cnt=1;
    }
  }
  sgs.push_back(cnt);
 // cout<<ans<<endl;
  for (int i =1; i < sgs.size(); ++i) {
   // cout<<sgs[i]<<" "<<sgs[i-1]<<endl;
    ans -= sgs[i] + sgs[i-1];
    ans++;
  }
  printf("%lld\n", ans);
  return 0;
}
