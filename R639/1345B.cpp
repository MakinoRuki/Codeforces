#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    ll ans=0LL;
    while(true) {
      ll i=1;
      for (i = 1; i*i <= n; ++i) {
        if (i*(3*i+1)/2 > n) break;
      }
      i--;
      if (i < 1) break;
      n -= i*(3*i+1)/2;
      ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
