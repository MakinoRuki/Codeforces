#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#define N 1000002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    ll ans=(1LL<<n);
    for (int i = 1; i < n/2; ++i) {
      ans += (1LL<<i);
    }
    for (int i = n/2; i < n; ++i) {
      ans -= (1LL<<i);
    }
    cout<<ans<<endl;
  }
  return 0;
}
