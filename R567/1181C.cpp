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
#define N 1002
using namespace std;
typedef long long ll;
int n, m;
vector<string> mp;
int sum[N][N];
int main() {
	cin>>n>>m;
	mp.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mp.push_back(s);
	}
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; ++i) {
		for (int j = m-1; j >= 0; --j) {
			if (j == m-1) sum[i][j] = 1;
			else {
				if (mp[i][j] == mp[i][j+1]) sum[i][j] = sum[i][j+1]+1;
				else sum[i][j] = 1;
			}
		}
	}
	ll ans=0LL;
	for (int j = 0; j < m; ++j) {
		vector<pair<pair<int, int>,int>> sgs;
		sgs.clear();
		int cnt=0;
		int minv=0;
		int id= 0;
		for (int i = 0; i < n; ++i) {
			if (i==0) {
				cnt=1;
				minv=sum[i][j];
			} else {
				if (mp[i][j]==mp[i-1][j]) {
					cnt++;
					minv = min(minv, sum[i][j]);
				} else {
					sgs.push_back(make_pair(make_pair(cnt, minv), id));
					id = i;
					cnt=1;
					minv = sum[i][j];
				}
			}
		}
		sgs.push_back(make_pair(make_pair(cnt, minv), id));
		for (int i = 1; i < sgs.size()-1; ++i) {
			if (sgs[i-1].first.first < sgs[i].first.first || sgs[i+1].first.first < sgs[i].first.first) {
				continue;
			}
			int minv = sgs[i].first.second;
			int id=sgs[i].second;
			for (int i2 = 1; i2 <= sgs[i].first.first; ++i2) {
				minv = min(minv, sum[id-i2][j]);
			}
			int id2 = id+sgs[i].first.first-1;
			for (int i2=1; i2 <= sgs[i].first.first;++i2) {
				minv= min(minv, sum[id2+i2][j]);
			}
			ans += minv;
		}
	}
	cout<<ans<<endl;
	return 0;
}
