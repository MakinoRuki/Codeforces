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
#define M 20005
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n,k,a,b;
int main() {
	cin>>n>>k>>a>>b;
	ll tot=0LL;
	if (k==1) {
		tot=(n-1)*a;
		cout<<tot<<endl;
		return 0;
	}
	while(n>1) {
		ll r=n%k;
	//	cout<<"n="<<n<<endl;
		if (r) {
			if (n-r>=1) {
				tot += r*a;
				n -= r;
			} else {
				tot += (n-1)*a;
				n = 1;
			}
		//	cout<<"tot="<<tot<<endl;
		} else {
			ll x=n/k;
			ll det=n-x;
			if (det*a < b) {
				tot += det*a;
			} else {
				tot += b;
			}
			n = x;
		//	cout<<"tot="<<tot<<endl;
		}
	}
	cout<<tot<<endl;
	return 0;
}
