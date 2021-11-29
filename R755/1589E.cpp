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
#define M 1000005
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
int s;
int t;
int n, k;
int a[N];
ll sum[N];
int query(vector<int>& q, ll det) {
	if (q.empty()) {
		return -1;
	}
	if (sum[q.back()] + det < 0) {
		return q.back()-1;
	}
	if (sum[q[0]] + det >= 0) {
		return n;
	}
	int l = 0, r = q.size()-1;
	while(l < r) {
		int mid = (l+r+1)/2;
		if (sum[q[mid]] + det >= 0) {
			r = mid-1;
		} else {
			l = mid;
		}
	}
	return q[r] - 2;
}
int getnum(vector<int>& v, int l, int r) {
	if (v.empty()) return 0;
	if (v.back() > r) return 0;
	if (v[0] < l) return 0;
	int x = 0, y = v.size()-1;
	while(x < y) {
		int mid = (x+y+1)/2;
		if (v[mid] < l) {
			y = mid-1;
		} else {
			x = mid;
		}
	}
	int x2 =0, y2 = v.size()-1;
	while(x2<y2) {
		int mid=(x2+y2)/2;
		if (v[mid] > r) {
			x2 = mid+1;
		} else {
			y2 = mid;
		}
	}
	return (y2 <= y ? y-y2+1 : 0);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		map<ll, vector<int>> ids[2];
		ids[0].clear();
		ids[1].clear();
		sum[0] = 0LL;
		for (int i = 1; i <= n; ++i) {
			sum[i] = a[i] - sum[i-1];
		}
		vector<int> q[2];
		ll ans = 0LL;
		for (int i = n; i >= 1; --i) {
			if (i == n) {
				q[n%2].push_back(i);
				ids[n%2][sum[i]].push_back(i);
			} else {
				int x= (i%2)>0;
				int rb1 = query(q[!x], -sum[i-1]);
				int rb2 = query(q[x], sum[i-1]);
				int rb = i;
				if (q[x].empty()) {
					rb = rb1;
				} else if (q[!x].empty()) {
					rb = rb2;
				} else {
					rb = min(rb1, rb2);
				}
				if (rb >= i+1) {
					ans += getnum(ids[x][-sum[i-1]], i+1, rb) + getnum(ids[!x][sum[i-1]], i+1, rb);
				}
				while(!q[x].empty() && sum[i] <= sum[q[x].back()]) {
					q[x].pop_back();
				}
				q[x].push_back(i);
				ids[x][sum[i]].push_back(i);
			}
			if (a[i] == 0) {
				ans++;
			}
		//	cout<<"i="<<i<<" "<<ans<<endl;
		}
		printf("%lld\n", ans);
	}
  return 0;
}

