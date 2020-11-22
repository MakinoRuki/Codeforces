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
#define N 2002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
vector<pair<int,int>> segs;
ll val[N][N];
ll calc(int l1, int r1, int l2, int r2) {
	if (l2<=r1 && l1<=r2) {
		return min(r1,r2)-max(l1,l2)+1;
	}
	return 0;
}
int main() {
	cin>>n>>m>>k;
	segs.clear();
	for (int i = 1; i <= m; ++i) {
		int l,r;
		scanf("%d%d", &l, &r);
		segs.push_back(make_pair(r,l));
	}
	// ll ans=0LL;
	// for (int i = 1; i + k- 1 <= n; ++i) {
	// 	ll cur=0LL;
	// 	vector<int> ids;
	// 	ids.clear();
	// 	for (int j = 0; j< segs.size(); ++j) {
	// 		int l = segs[j].first;
	// 		int r = segs[j].second;
	// 		if (ispre(i, i+k-1, l, r)) {
	// 			cur += calc(i, i+k-1, l, r);
	// 		} else {
	// 			ids.push_back(j);
	// 		}
	// 	}
	// 	for (int )
	// }
//	cout<<"??"<<endl;
	sort(segs.begin(), segs.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
		return x.first+x.second < y.first+y.second;
	});
	memset(val, 0LL, sizeof(val));
//	cout<<">>"<<endl;
	for (int i = 1; i+k-1 <= n; ++i) {
		for (int j = m; j >= 1; --j) {
	//		if (i==6 && j==4) cout<<"x="<<i<<" "<<i+k-1<<" "<<segs[j-1].first<<" "<<segs[j-1].second<<endl;
			val[i][j] = val[i][j+1] + calc(i, i+k-1, segs[j-1].second, segs[j-1].first);
		}
	}
	for (int i = n; i >= 1; --i) {
		if (i+k-1<n) {
			for (int j = 1; j <= m; ++j) {
				val[i][j] = max(val[i+1][j], val[i][j]);
			}
		}
	}
	// cout<<val[6][4]<<endl;
	// cout<<"!!"<<endl;
	ll ans=0LL;
	for (int i = 1; i+k-1 <= n; ++i) {
		ll cur=0LL;
		ans = max(ans, val[i][1]);
		int j;
		for (j = 0; j < segs.size(); ++j) {
			// if (i >= segs[j].first-k+1) {
			// 	cur += calc(i, i+k-1, segs[j].second, segs[j].first);
			// } else {
			// 	break;
			// }
			cur += calc(i, i+k-1, segs[j].second, segs[j].first);
			if (j+2<=segs.size()) ans = max(ans, cur+val[i][j+2]);
			else ans = max(ans, cur);
		}
		// if (j>=segs.size()) {
		// 	ans=max(ans, cur);
		// }
		// for (int i2 = i; i2 +k-1 <= n; ++i2) {
		// 	ll cur2 =cur;
		// 	if (j<segs.size()) {
		// 		cur2 += val[i2][j+1];
		// 	}
		// 	ans=max(ans, cur2);
		// }
	}
	cout<<ans<<endl;
	return 0;
}
