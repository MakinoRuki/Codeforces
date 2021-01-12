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
#define M 31
#define N 35
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int l;
ll c[N];
int main() {
  cin>>n>>l;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &c[i]);
  }
  for (int i = 1; i <= 31; ++i) {
    int x = 1<<(i-1);
    if (i > n) c[i] = (1LL<<60)-1;
    for (int j = 0; j < i-1; ++j) {
      if (c[j+1] * (1LL<<(i-1-j)) < c[i]) {
        c[i] = c[j+1] * (1LL<<(i-1-j));
      }
    }
    //cout<<i<<" "<<c[i]<<endl;
  }
  ll ans=c[31];
  ll cur=0LL;
  ll tot=0LL;
  for (int i = 30; i >= 1; --i) {
    if ((1LL<<(i-1)) & l) {
      tot += (1LL<<(i-1));
    //  cout<<"i="<<(i-1)<<endl;
      cur += c[i];
    } else {
      cur += c[i];
      ans=min(ans, cur);
      cur -= c[i];
    }
  }
  ans = min(ans, cur);
 // cout<<"tot="<<tot<<endl;
  cout<<ans<<endl;
  return 0;
}
