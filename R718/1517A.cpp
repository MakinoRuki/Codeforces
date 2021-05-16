#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 200005
#define M 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t;
ll n;
ll pw[16];
int main() {
	pw[0] = 1LL;
	for (int i = 1; i <= 15; ++i) {
		pw[i] = pw[i-1] * 10LL;
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld", &n);
		ll ans =0LL;
		for (int i = 15; i >= 0; --i) {
			ll cur = 2050LL*pw[i];
			ans += n/cur;
			n %= cur;
		}
		if (n == 0) {
			printf("%lld\n", ans);
		} else {
			puts("-1");
		}
	}
	return 0;
}

/*myturn.ca.gov*/
