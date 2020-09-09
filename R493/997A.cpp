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
#define N 1000005
#define eps 1e-6
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
ll x, y;
string s;
int main() {
	cin>>n>>x>>y;
	cin>>s;
	int zn = 0;
	bool zero = false;
	for (int i = 0; i < n; ++i) {
		if (s[i]=='1') {
			if (zero) {
				zn++;
				zero = false;
			}
		} else {
			zero=true;
		}
	}
	if (zero) {
		zn++;
	}
	if (zn==0) {
		cout<<0<<endl;
		return 0;
	}
	ll res;
	if (x >= y) {
		res=(ll)y*(ll)zn;
	} else {
		res = (ll)(zn-1)*(ll)x+(ll)y;
	}
	printf("%lld\n", res);
	return 0;
}
