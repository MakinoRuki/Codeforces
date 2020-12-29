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
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll k,l,r,t,x,y;
int main() {
	cin>>k>>l>>r>>t>>x>>y;
	if (k + y >= l && k + y <= r) {
		k += y;
	}
	if (x == y) {
		if (k-x >= l && k-x <= r) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	} else if (x>y) {
		if (k - l - y > 0 && (k-l-y)/(x-y)>=t) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	} else {
		for (int i = 1; i <= x+1; ++i) {
			ll day = (k+y-r+x-1)/x;
			if (day > t) day = t;
			if (k-day*x < l) {
				cout<<"No"<<endl;
				return 0;
			}
			k -= day*x;
			t -= day;
			if (t <= 0) break;
			k += y;
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}
