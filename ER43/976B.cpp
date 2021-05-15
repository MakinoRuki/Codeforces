#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <deque>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
ll n, m;
ll k;
int main() {
	cin>>n>>m>>k;
	if (k <= n-1) {
		printf("%lld %d\n", k+1, 1);
	} else {
		k -= (n-1);
		ll q = k/(m-1);
		ll r = k%(m-1);
		ll x , y;
		if (r == 0) {
			x = n-q+1;
			if (q % 2 == 0) y = 2;
			else y = m;
		} else {
			x = n-q;
			if (q % 2 == 0) y = 1+r;
			else y = m-r+1;
		}
		printf("%lld %lld\n", x, y);
	}
	return 0;
}
