#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 200010
using namespace std;
typedef long long ll;
int n, q;
int a[N];
ll bit[N];
set<int> groups[32];
int getbit(int x) {
	return (x & (-x));
}
void add(int p, int x) {
	while(p <= n) {
		bit[p] += x;
		p += getbit(p);
	}
}
ll sum(int p) {
	ll res = 0LL;
	while(p > 0) {
		res += bit[p];
		p -= getbit(p);
	}
	return res;
}
int getmaxbit(int x) {
	for (int i = 30; i >= 0; --i) {
		if ((1<<i) & x) return (i + 1);
	}
	return 0;
}
int main() {
	cin>>n>>q;
	memset(bit, 0, sizeof(bit));
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
		add(i, a[i]);
		groups[getmaxbit(a[i])].insert(i);
	}
	for (int i = 0; i < q; ++i) {
		int p, x;
		cin>>p>>x;
		int maxb1 = getmaxbit(a[p]);
		int maxb2 = getmaxbit(x);
		add(p, x - a[p]);
		a[p] = x;
		groups[maxb1].erase(p);
		groups[maxb2].insert(p);
		int ans = -1;
		for (int j = 0; j <= 30; ++j) {
			int cnt = 0;
			for (set<int>::iterator itr = groups[j].begin(); itr != groups[j].end(); ++itr) {
				int pos = *itr;
				ll s = sum(pos - 1);
				if (s == a[pos]) {
					ans = pos;
					break;
				}
				cnt++;
				if (cnt >= 2) break;
			}
			if (ans != -1) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
