#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
int t;
ll a, b;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>a>>b;
    ll pn[11];
    pn[1] = 9;
    for (int i = 2; i <= 10; ++i) {
      pn[i] = pn[i-1] * 10LL + 9LL;
    }
    ll ans = 0LL;
    for (int i = 1; i <= 9; ++i) {
      if (pn[i] <= b) {
        ans += a;
      }
    }
    cout<<ans<<endl;
  }
	return 0;
}
