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
#include <queue>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n,k;
int main() {
	//cin>>n>>k;
	// if (n%2==0) {
	// 	if (k<=1) cout<<"Yes"<<endl;
	// 	else {
	// 		cout<<"No"<<endl;
	// 	}
	// } else {

	// }
	cin>>n>>k;
	set<ll> ss;
	ss.clear();
	bool ok=true;
	for (int i = 1; i <= min(k, (ll)5000000); ++i) {
		if (ss.find(n%i)!=ss.end()) {
			ok=false;
			break;
		}
		ss.insert(n%i);
	}
	if (ok) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	// cin>>n;
	// for (int i =1 ; i<= 30; ++i) {
	// 	cout<<i<<" "<<n%i<<endl;
	// }
	return 0;
}
