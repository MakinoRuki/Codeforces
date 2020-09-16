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
#define N 2000
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int c0[N], c1[N];
vector<pair<int,int>> seg;
int main() {
	cin>>n>>m;
	memset(c0, 0, sizeof(c0));
	memset(c1, 0, sizeof(c1));
	seg.clear();
	for (int i = 0; i < m; ++i) {
		int l,r;
		scanf("%d%d", &l, &r);
		seg.push_back(make_pair(l,r));
	}
	string ans="";
	for (int i = 1; i <= n; ++i) {
		int n00=0,n01=0,n10=0;
		for (int j = 0; j < seg.size(); ++j) {
			if (seg[j].first<=i && seg[j].second>=i) {
				if (c0[j]==c1[j]) {
					n00++;
				} else if (c0[j]>c1[j]) {
					n01++;
				} else {
					n10++;
				}
			}
		}
		if (n01) {
			ans += "1";
			for (int j = 0; j < seg.size(); ++j) {
				if (seg[j].first<=i && seg[j].second>=i) {
					c1[j]++;
				}
			}
		} else if (n10) {
			ans += "0";
			for (int j = 0; j < seg.size(); ++j) {
				if (seg[j].first<=i && seg[j].second>=i) {
					c0[j]++;
				}
			}
		} else {
			ans += "1";
			for (int j = 0; j < seg.size(); ++j) {
				if (seg[j].first<=i && seg[j].second>=i) {
					c1[j]++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
