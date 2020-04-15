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
#define N 400005
using namespace std;
typedef long long ll;
int t, n;
ll I;
int a[N];
int main() {
	cin>>n>>I;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ll k = 8*I/n;
	k = (k >= 30 ? n : (1LL<<k));
	sort(a+1, a+n+1);
	vector<pair<int, int>> ns;
	ns.clear();
	int cnt=0;
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			cnt=1;
		} else {
			if (a[i]==a[i-1]) cnt++;
			else {
				ns.push_back(make_pair(a[i-1], cnt));
				cnt=1;
			}
		}
	}
	ns.push_back(make_pair(a[n], cnt));
	sort(ns.begin(), ns.end());
	int tot=0;
	int ans=n;
	for (int i = 0; i < ns.size(); ++i) {
		tot += ns[i].second;
		if (i >= k) tot -= ns[i-k].second;
		if (i >= k-1) {
			ans = min(ans, n-tot);
		}
	}
	ans = min(ans, n-tot);
	cout<<ans<<endl;
	return 0;
}
