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
#define N 100005
using namespace std;
typedef long long ll;
int t;
ll n;
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n;
		ll row = (n+2)/3;
		ll col = 3;
		if (n % 3 != 0) {
			col = n-n/3*3;
		}
		ll pw = 1LL;
		while(pw < row) {
			row -= pw;
			pw *= 4LL;
		}
		ll a = pw + row-1;
		ll b = pw * 2LL;
		for (ll p = pw/4; p >= 1; p /= 4) {
			ll r = (row-1)/p;
			if (r==1) b += p*2;
			else if (r==2) b += 2*p + p;
			else if (r == 3) b += p;
			row = row-r*p;
		}
		if (col == 1) cout<<a<<endl;
		else if (col==2) cout<<b<<endl;
		else cout<<(a^b)<<endl;
	}
	return 0;
}
