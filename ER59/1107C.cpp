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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,k;
int a[N];
string s;
int main() {
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	cin>>s;
	ll ans=0LL;
	vector<ll> ds;
	ds.clear();
	for (int i = 0; i < n; ++i) {
		if (i==0 || s[i]==s[i-1]) {
			ds.push_back(a[i+1]);
		} else {
			sort(ds.begin(), ds.end());
			reverse(ds.begin(), ds.end());
			for (int j = 0; j < min(k, (int)ds.size()); ++j) {
				ans += ds[j];
			}
			ds.clear();
			ds.push_back(a[i+1]);
		}
	}
	if (ds.size()>0) {
		sort(ds.begin(), ds.end());
		reverse(ds.begin(), ds.end());
		for (int i = 0; i < min(k, (int)ds.size()); ++i) {
			ans += ds[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
