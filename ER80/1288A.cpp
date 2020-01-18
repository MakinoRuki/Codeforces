#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
int t;
ll n, d;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>d;
    ll y = sqrt(d-1);
    bool ok = false;
    for (ll x = max(y-2, 0LL); x <= y+2; ++x) {
      ll res = (x+1) + (d-1)/(x+1);
      if (res <= n) {
        ok = true;
        break;
      }
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
	return 0;
}
