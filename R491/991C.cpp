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
#define N 105
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n;
bool check(ll k) {
	ll n1=0,n2=0;
	ll m=n;
	while(m) {
		if (m<=k) {
			n1+=m;
			break;
		} else {
			n1+=k;
			m-=k;
		}
		if (m<10) {
			continue;
		} else {
			n2+=m/10;
			m -= m/10;
		}
	}
	return 2*n1>=n;
}
int main() {
	cin>>n;
	ll l=1, r=n;
	while(l<r) {
		ll mid=(l+r)/2;
		if (check(mid)) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	cout<<r<<endl;
	return 0;
}
