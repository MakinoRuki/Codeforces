#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define N 2005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll l, r;
vector<int> ld;
vector<int> rd;
ll dp[34][2][2][2][2];
ll dfs(int cur, int a1, int a2, int b1, int b2) {
	if (dp[cur][a1][a2][b1][b2] >=0) return dp[cur][a1][a2][b1][b2];
	if (cur > 32) return 1;
	dp[cur][a1][a2][b1][b2] = 0;
	// cout<<"cur="<<cur<<endl;
	// cout<<"ld="<<ld[cur]<<" "<<"rd="<<rd[cur]<<endl;
	for (int c1 = 0; c1 < 2; ++c1) {
		for (int c2 = 0; c2 < 2; ++c2) {
			if (c1 && c2) continue;
			if (!a1 && c1 > rd[cur]) continue;
			if (!a2 && c1 < ld[cur]) continue;
			if (!b1 && c2 > rd[cur]) continue;
			if (!b2 && c2 < ld[cur]) continue;
			//cout<<"cur="<<cur<<" "<<"a1="<<a1<<" "<<"a2="<<a2<<" "<<"c="<<c1<<" "<<c2<<endl;
			dp[cur][a1][a2][b1][b2] += dfs(cur+1, a1 | (c1 < rd[cur]), a2 | (c1 > ld[cur]), b1 | (c2 < rd[cur]), b2 | (c2 > ld[cur]));
			//cout<<
		}
	}
	return dp[cur][a1][a2][b1][b2];
}
void getds(ll x, vector<int>& ds) {
	for (int i = 0; i < 33; ++i) {
		ds.push_back(((1LL<<(32-i)) & x) > 0);
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ld.clear();
		rd.clear();
		cin>>l>>r;
		getds(l, ld);
		getds(r, rd);
		memset(dp, -1, sizeof(dp));
		dfs(0, 0, 0, 0, 0);
		cout<<dp[0][0][0][0][0]<<endl;
	}
	return 0;
}
