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
ll k, d, t;
int main() {
  cin>>k>>d>>t;
  if (k%d==0) {
    printf("%.10lf\n", (double)t);
  } else {
    ll r = k%d;
    r = d - r;
    ll p = k+r;
    ll q = 2*t/(2*k+r);
    ll x = 2*t-q*(2*k+r);
  //  cout<<p<<" "<<q<<" "<<x<<endl;
    if (x<=2*k) {
      printf("%.10lf\n", (double)p*(double)q+(double)x*0.5);
    } else {
      ll y = 2*t-q*(2*k+r) - 2*k;
      printf("%.10lf\n", (double)q*(double)p + (double)k+(double)y);
    }
  }
  return 0;
}
