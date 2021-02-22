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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll a[5][N];
vector<int> r[5][N];
int nn1,nn2,nn3,nn4;
int m1,m2,m3,m4;
ll dp[5][N];
int idx[N];
int main() {
	cin>>nn1>>nn2>>nn3>>nn4;
	for (int i = 1; i <= nn1; ++i) {
		scanf("%lld", &a[1][i]);
	}
	for (int i = 1; i <= nn2; ++i) {
		scanf("%lld", &a[2][i]);
	}
	for (int i = 1; i <= nn3; ++i) {
		scanf("%lld", &a[3][i]);
	}
	for (int i = 1; i <= nn4; ++i) {
		scanf("%lld", &a[4][i]);
	}
	cin>>m2;
	for (int i =1; i <= m2; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		r[2][y].push_back(x);
	}
	cin>>m3;
	for (int i =1; i <= m3; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		r[3][y].push_back(x);
	} 
	cin>>m4;
	for (int i =1; i <= m4; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		r[4][y].push_back(x);
	} 
	vector<pair<ll, int>> rk;
	rk.clear();
	for (int i= 1; i <= 4; ++i) {
		for (int j = 1; j < N; ++j) {
			dp[i][j] = (1LL<<60)-1;
		}
	}
	for (int i = 1; i <= nn1; ++i) {
		rk.push_back(make_pair(a[1][i], i));
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < rk.size(); ++i) {
		idx[rk[i].second] = i;
	}
	for (int i = 1; i <= nn2; ++i) {
		vector<pair<int,int>> ids;
		for (int j = 0; j < r[2][i].size(); ++j) {
			ids.push_back(make_pair(idx[r[2][i][j]], r[2][i][j]));
		}
		sort(ids.begin(), ids.end());
		int j = 0;
		if (ids.empty()) {
			dp[2][i] = rk[0].first + a[2][i];
		} else {
			for (int j2 = 0; j2 < ids.size(); ++j2) {
				if (ids[j2].first == j) {
					j++;
				} else {
					dp[2][i] = rk[j].first + a[2][i];
					break;
				}
			}
			if (j < rk.size()) dp[2][i] = min(dp[2][i], rk[j].first+a[2][i]);
		}
	//	cout<<"n2i="<<i<<" "<<dp[2][i]<<endl;
	}
	rk.clear();
	for (int i = 1; i <= nn2; ++i) {
		rk.push_back(make_pair(dp[2][i], i));
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < rk.size(); ++i) {
		idx[rk[i].second] = i;
	}
	for (int i = 1; i <= nn3; ++i) {
		vector<pair<int,int>> ids;
		for (int j = 0; j < r[3][i].size(); ++j) {
			ids.push_back(make_pair(idx[r[3][i][j]], r[3][i][j]));
		}
		sort(ids.begin(), ids.end());
		int j = 0;
		if (ids.empty()) {
			dp[3][i] = rk[0].first + a[3][i];
		} else {
			for (int j2 = 0; j2 < ids.size(); ++j2) {
				if (ids[j2].first == j) {
					j++;
				} else {
					dp[3][i] = rk[j].first + a[3][i];
					break;
				}
			}
			if (j < rk.size()) dp[3][i] = min(dp[3][i], rk[j].first+a[3][i]);
		}
	}
	rk.clear();
	for (int i = 1; i <= nn3; ++i) {
		rk.push_back(make_pair(dp[3][i], i));
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < rk.size(); ++i) {
		idx[rk[i].second] = i;
	}
	for (int i = 1; i <= nn4; ++i) {
		vector<pair<int,int>> ids;
		for (int j = 0; j < r[4][i].size(); ++j) {
			ids.push_back(make_pair(idx[r[4][i][j]], r[4][i][j]));
		}
		sort(ids.begin(), ids.end());
		int j = 0;
		if (ids.empty()) {
			dp[4][i] = rk[0].first + a[4][i];
		} else {
			for (int j2 = 0; j2 < ids.size(); ++j2) {
				if (ids[j2].first == j) {
					j++;
				} else {
					dp[4][i] = rk[j].first + a[4][i];
					break;
				}
			}
			if (j < rk.size()) dp[4][i] = min(dp[4][i], rk[j].first+a[4][i]);
		}
	}
	ll ans = (1LL<<60)-1;
	for (int i = 1; i <= nn4; ++i) {
		ans = min(ans, dp[4][i]);
	}
	if (ans < (1LL<<60)-1) cout<<ans<<endl;
	else cout<<-1<<endl;
  return 0;
}

