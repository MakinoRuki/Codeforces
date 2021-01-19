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
#include <random>
#define eps 1e-7
#define M 21
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n;
int k;
int main() {
  cin>>n>>k;
  ll l = 1, r = n;
  mt19937_64 rng(51);
  while(true) {
    if (r-l>4*k) {
      ll mid = (l+r)/2;
      printf("%lld %lld\n", l, mid);
      fflush(stdout);
      string res;
      cin>>res;
      if (res == "Yes") {
        if (mid==l) return 0;
        l = max(l-k, 1LL);
        r = min(mid+k, n);
      } else {
        l = max(mid+1-k, 1LL);
        r = min(r+k, n);
      }
    } else {
      ll p = rng()%(r-l+1);
      printf("%lld %lld\n", l+p, l+p);
      fflush(stdout);
      string res;
      cin>>res;
      if (res=="Yes") {
        return 0;
      }
      l = max(l-k, 1LL);
      r = min(r+k, n);
    }
  }
  return 0;
}
