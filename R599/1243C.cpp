#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
typedef long long ll;
ll n;
int main() {
	cin>>n;
	vector<ll> ps;
	ps.clear();
	ll m = n;
	for (ll i = 2; i * i <= n; ++i) {
		if (n%i == 0) {
			if (ps.size() < 2) ps.push_back(i);
			if (ps.size() >= 2) break;
			while(n%i == 0) n /= i;
			//cout<<"i="<<i<<endl;
		}
	}
	//cout<<n<<endl;
	if (n == m) {
		cout<<n<<endl;
	} else {
		if (n > 1) {
			ps.push_back(n);
		}
		if (ps.size() == 1) cout<<ps[0]<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
