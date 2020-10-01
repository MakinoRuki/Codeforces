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
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll a[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	a[0]=0LL;
	for (int i = 1; i <= n; ++i) {
		a[i]+=a[i-1];
	}
	ll tot=0LL;
	set<ll> ss;
	ss.clear();
	ss.insert(0);
	for (int i = 1; i <= n; ++i) {
		if (ss.find(a[i]) != ss.end()) {
			tot++;
			ss.clear();
			ss.insert(a[i-1]);
		}
		ss.insert(a[i]);
	}
	printf("%lld\n", tot);
	return 0;
}
