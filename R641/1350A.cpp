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
#define N 502
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll n, k;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    ll ans;
    if (n%2 == 0) {
      ans = n + k*2;
    } else {
      ll i = 2;
      for (i = 2; i * i <= n; ++i) {
        if (n%i == 0) break;
      }
      if (i*i > n) {
        ans = n*2;
        ans += (k-1)*2;
      } else {
        ans = n + i;
        ans += (k-1)*2;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
