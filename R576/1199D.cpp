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
#define N 200005
using namespace std;
typedef long long ll;
int n;
int a[N];
int q;
int ans[N];
vector<pair<int, pair<int,int>>> qs;
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	qs.clear();
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		int f;
		cin>>f;
		if (f == 1) {
			int p,x;
			cin>>p>>x;
			qs.push_back(make_pair(1, make_pair(p,x)));
		} else {
			int x;
			cin>>x;
			qs.push_back(make_pair(2, make_pair(-1, x)));
		}
	}
	int minv = -1;
	memset(ans, -1, sizeof(ans));
	for (int i = q-1; i >= 0; --i) {
		int f = qs[i].first;
		int p = qs[i].second.first;
		int x = qs[i].second.second;
	//	cout<<f<<" "<<p<<" "<<x<<endl;
		if (f == 1) {
			if (ans[p] < 0) {
				ans[p] = max(minv, x);
			//	cout<<ans[p]<<endl;
			}
		} else {
			minv = max(minv, x);
		}
	//	cout<<minv<<endl;
	}
	for (int i = 1; i <= n; ++i) {
	//	cout<<"i="<<i<<" "<<ans[i]<<endl;
		if (ans[i] < 0) {
			ans[i] = max(a[i], minv);
		}
	//	cout<<ans[i]<<endl;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d", ans[i]);
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
