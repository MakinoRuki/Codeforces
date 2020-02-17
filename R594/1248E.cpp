#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
int n, p;
int t[N];
ll ans[N];
int main() {
	cin>>n>>p;
	set<pair<ll, pair<int, int>>> rks;
	rks.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
		rks.insert(make_pair(t[i], make_pair(0, i)));
	}
	set<int> q1;
	set<int> q2;
	q1.clear();
	q2.clear();
	ll ct = 0;
	while(!rks.empty()) {
		auto cur = *rks.begin();
		ll tm = cur.first;
		int f = cur.second.first;
		int id = cur.second.second;
		rks.erase(cur);
		if (!f) {
			if (q1.empty() || *q1.begin() > id) {
				q1.insert(id);
				ct = max(ct, tm);
				rks.insert(make_pair(ct+p, make_pair(1, id)));
				ct += p;
			} else {
				q2.insert(id);
			}
		} else {
			ans[id] = tm;
			q1.erase(id);
			if (!q2.empty()) {
				if (q1.empty() || *q2.begin() < *q1.begin()) {
					int x = *q2.begin();
					q2.erase(x);
					q1.insert(x);
					rks.insert(make_pair(ct + p, make_pair(1, x)));
					ct += p;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%lld", ans[i]);
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
