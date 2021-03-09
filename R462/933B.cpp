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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
ll p, k;
int main() {
  cin>>p>>k;
  vector<ll> ans;
  ans.clear();
  int bit = 0;
  while(p) {
  //  if (p>1) cout<<"p="<<p<<endl;
    ll r = p % k;
    if (r == 0) {
      ans.push_back(0);
      p /= k;
    } else {
      if (!bit) {
        ans.push_back(r);
        p -= r;
      } else {
        ans.push_back(k-r);
        p += (k-r);
      }
      p /= k;
    }
    bit = !bit;
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%lld", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
