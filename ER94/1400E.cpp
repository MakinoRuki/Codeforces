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
#define N 5002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N];
ll dfs(int l, int r) {
	if (l > r) return 0LL;
	ll minv = a[l];
	int id = l;
	for (int i = l; i <= r; ++i) {
		if (a[i] < minv) {
			minv = a[i];
			id = i;
		}
	}
	ll taken = max(a[l-1], a[r+1]);
	ll res = minv-taken + dfs(l, id-1) + dfs(id+1, r);
	res = min(res, (ll)r-l+1);
	return res;
}
int main() {
	cin>>n;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ll ans = dfs(1, n);
	printf("%lld\n", ans);
	return 0;
}

/*
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
#define N 5002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N];
ll dfs(int l, int r, ll taken) {
	if (l > r) return 0LL;
	ll minv = a[l];
	int id = l;
	for (int i = l; i <= r; ++i) {
		if (a[i] < minv) {
			minv = a[i];
			id = i;
		}
	}
	ll res = minv-taken + dfs(l, id-1, minv) + dfs(id+1, r, minv);
	res = min(res, (ll)r-l+1);
	return res;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ll ans = dfs(1, n, 0);
	printf("%lld\n", ans);
	return 0;
}
*/
