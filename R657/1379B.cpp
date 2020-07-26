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
#define N 105
#define M 20010
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, l, r;
ll m;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>l>>r>>m;
		ll x = max(1LL, m+l-r);
		ll y = m+r-l;
		ll a;
		ll b,c;
		ll n = -1;
		for (a = l; a <= r; ++a) {
			ll i1 = (x+a-1)/a;
			ll i2 = y/a;
			if (i1 <= i2) {
				n = i1;
				ll det = m-n*a;
			//	cout<<"i="<<x<<" "<<y<<" "<<a<<" "<<n<<" "<<det<<endl;
				if (det >= 0) {
					c = l;
					b = c+det;
				} else {
					c = r;
					b = c+det;
				}
				break;
			}
		}
		if (n > 0) {
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
	}
  return 0;
}
