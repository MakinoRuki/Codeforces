#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
int a[N];
int main() {
	cin>>n;
	ll ans= (ll)n*(ll)(n+1)/2LL;
	map<ll, int> sums;
	sums.clear();
	ll sum=0LL;
	sums[0] = 0;
	int pre = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
		if (sums.find(sum) != sums.end()) {
			int id = sums[sum];
			pre = max(pre, id+1);
		}
		if (pre >= 0) {
			ans -= pre;
		}
		sums[sum] = i;
	}
	cout<<ans<<endl;
	return 0;
}
