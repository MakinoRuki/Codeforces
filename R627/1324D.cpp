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
const ll mod = 1000000007LL;
int n;
int a[N], b[N];
int id[N];
int BIT[N];
int cnt;
int lowbit(int x) {
	return x&(-x);
}
void update(int pos) {
	while(pos <= cnt) {
		BIT[pos]++;
		pos += lowbit(pos);
	}
}
int query(int pos) {
	int sum=0;
	while(pos) {
		sum += BIT[pos];
		pos -= lowbit(pos);
	}
	return sum;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	vector<pair<int, int>> rk;
	for (int i = 1; i <= n; ++i) {
		rk.push_back(make_pair(b[i]-a[i], i));
	}
	sort(rk.begin(), rk.end());
	cnt=0;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || rk[i].first != rk[i-1].first) {
			cnt++;
		}
		id[rk[i].second] = cnt;
	}
	memset(BIT, 0, sizeof(BIT));
	vector<int> rk2;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || rk[i].first != rk[i-1].first) {
			rk2.push_back(rk[i].first);
		}
	}
	ll tot=0;
	for (int i = n; i >= 1; --i) {
		auto itr = lower_bound(rk2.begin(), rk2.end(), a[i]-b[i]);
		tot += query(itr-rk2.begin());
		update(id[i]);
	}
	cout<<tot<<endl;
	return 0;
}
