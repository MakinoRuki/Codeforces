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
#define M 52
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<pair<int,int>> ac;
ll dis[N];
int main() {
	cin>>n;
	ac.clear();
	ll tot=0LL;
	for (int i = 1; i <= n; ++i) {
		int a,c;
		scanf("%d%d", &a, &c);
		ac.push_back(make_pair(a, c));
		tot += (ll)c;
	}
	sort(ac.begin(), ac.end());
	for (int i = 0; i < n; ++i) {
		dis[i] = (1LL<<60)-1;
	}
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push(make_pair(0, 0));
	dis[0] = 0;
	while(!pq.empty()) {
		auto pr = pq.top();
		pq.pop();
		ll ds = pr.first;
		int idx = pr.second;
		if (ds > dis[idx]) {
			continue;
		}
		if (idx == n-1) {
			tot += dis[idx];
			break;
		}
		if (idx > 0 && dis[idx] < dis[idx-1]) {
			dis[idx-1] = dis[idx];
			pq.push(make_pair(dis[idx], idx-1));
		}
		int l = idx, r = n-1;
		while(l < r) {
			int mid = (l+r+1)/2;
			if (ac[idx].first+ac[idx].second >= ac[mid].first) {
				l = mid;
			} else {
				r = mid-1;
			}
		}
		if (r != idx && dis[r] > dis[idx]) {
			dis[r] = dis[idx];
			pq.push(make_pair(dis[idx], r));
		}
		if (r + 1 < n && dis[r+1] > dis[idx] + ac[r+1].first - ac[idx].first - ac[idx].second) {
			dis[r+1] = (ll)dis[idx] + (ll)ac[r+1].first - (ll)ac[idx].first - (ll)ac[idx].second;
			pq.push(make_pair((ll)dis[idx] + (ll)ac[r+1].first - (ll)ac[idx].first - (ll)ac[idx].second, r + 1));
		}
	}
	printf("%lld\n", tot);
  return 0;
}
