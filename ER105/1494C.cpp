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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
int a[N], b[N];
int cnt1[N], cnt2[N];
int getres(vector<int>& x, vector<int>& y) {
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int j = 0;
	cnt1[0] = 0;
	for (int i = 1; i <= y.size(); ++i) {
		while(j < x.size() && x[j] <= y[i-1]) {
			j++;
		}
		cnt1[i] = j;
	}
	set<int> ss(x.begin(), x.end());
	cnt2[(int)y.size()+1] = 0;
	for (int i = y.size(); i >= 1; --i) {
		cnt2[i] = cnt2[i+1];
		if (i+1<=y.size() && ss.find(y[i]) != ss.end()) {
			cnt2[i]++;
		}
	}
	int res = 0;
	for (int i = 1; i <= y.size(); ++i) {
		int l = 1, r = i+1;
		while(l < r) {
			int mid = (l+r)/2;
			if (y[i-1]-y[mid-1]+1 <= cnt1[i]) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		if (r <= i) {
			res = max(res, i-r+1+cnt2[i]);
		}
		// if (i == 2) {
		// 	cout<<"x="<<r<<" "<<cnt1[i]<<" "<<cnt2[i]<<endl;
		// }
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &b[i]);
		}
		vector<int> x, y;
		x.clear();
		y.clear();
		for (int i = 1; i <= n; ++i) {
			if (a[i] > 0) {
				x.push_back(a[i]);
			}
		}
		for (int i = 1; i <= m; ++i) {
			if (b[i] > 0) {
				y.push_back(b[i]);
			}
		}
		int ans = getres(x, y);
	//	cout<<ans<<endl;
		x.clear();
		y.clear();
		for (int i = 1; i <= n; ++i) {
			if (a[i] < 0) {
				x.push_back(-a[i]);
			}
		}
		for (int i = 1; i <= m; ++i) {
			if (b[i] < 0) {
				y.push_back(-b[i]);
			}
		}
		ans += getres(x, y);
		printf("%d\n", ans);
	}
  return 0;
}
