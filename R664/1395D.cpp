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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int n, d, m;
int a[N];
ll sum1[N], sum2[N];
int main() {
	cin>>n>>d>>m;
	vector<int> a1, a2;
	a1.clear();
	a2.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] <= m) {
			a1.push_back(a[i]);
		} else {
			a2.push_back(a[i]);
		}
	}
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	reverse(a1.begin(), a1.end());
	memset(sum1, 0LL, sizeof(sum1));
	memset(sum2, 0LL, sizeof(sum2));
	for (int i = 1; i <= a1.size(); ++i) {
		sum1[i] = sum1[i-1]+a1[i-1];
	}
	for (int i = 1; i <= a2.size(); ++i) {
		sum2[i] = sum2[i-1]+a2[i-1];
	}
	ll ans = 0LL;
	ll pre = 0LL;
	if (a1.size() >= n) {
		ans = sum1[n];
	}
	int sz = a2.size();
	for (int i = 1; i <= sz; ++i) {
		pre += a2[sz-i];
		ll rm = n-(ll)(i-1)*(ll)d-i;
		if (rm >= 0) {
			int sz1 = (int)a1.size();
			if (rm <= sz1) {
				ans = max(ans, pre + sum1[rm]);
			} else if (sz-(ll)(i-1)*(ll)d-i<=d) {
				ans = max(ans, pre + sum1[sz1]);
			}
		}
		// int rm = (i-1)*d;
		// rm -= min(rm, sz-i);
		// if (n-rm-i >= 0 && (int)a1.size()-rm == n-rm-i) {
		// 	ans = max(ans, pre + sum1[n-rm-i]);
		// }
	}
	cout<<ans<<endl;
	return 0;
}
