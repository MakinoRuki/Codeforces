#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int a[N];
string s, t;
int main() {
	cin>>n;
	cin>>s>>t;
	int a = 0;
	int b = 0;
	unordered_set<int> ids[2][2];
	vector<pair<int, int>> ans;
	ans.clear();
	for (int i = 0; i < n; ++i) {
		if (s[i]=='a' && t[i] == 'a') {
			ids[0][0].insert(i);
		}
		if (s[i]=='a' && t[i]=='b') {
			ids[0][1].insert(i);
		}
		if (s[i] == 'b' && t[i] == 'a') {
			ids[1][0].insert(i);
		}
		if (s[i] == 'b' && t[i] == 'b') {
			ids[1][1].insert(i);
		}
	}
	int tot=0;
	if (ids[0][1].size() % 2 && ids[1][0].size() % 2) {
		int x = *ids[0][1].begin();
		// if (ids[0][0].size() == 0 && ids[1][1].size() == 0) {
		// 	cout<<"-1"<<endl;
		// 	return 0;
		// }
		ids[1][0].insert(x);
		ans.push_back(make_pair(x+1, x+1));
		// if (ids[0][0].size() > 0) {
		// 	int y = *ids[0][0].begin();
		// 	ans.push_back(make_pair(y+1, x+1));
		// 	tot++;
		// 	ids[1][0].insert(y);
		// } else {
		// 	int y = *ids[1][1].begin();
		// 	ans.push_back(make_pair(x+1, y+1));
		// 	tot++;
		// 	ids[1][0].insert(y);
		// }
		ids[0][1].erase(x);
	}
	if (ids[0][1].size() % 2 || ids[1][0].size() % 2) {
		cout<<"-1"<<endl;
		return 0;
	}
	vector<int> v1(ids[0][1].begin(), ids[0][1].end());
	vector<int> v2(ids[1][0].begin(), ids[1][0].end());
	for (int i = 0; i < v1.size(); i += 2) {
		ans.push_back(make_pair(v1[i]+1, v1[i+1]+1));
	}
	for (int i = 0; i < v2.size(); i+=2) {
		ans.push_back(make_pair(v2[i]+1, v2[i+1]+1));
	}
	cout<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
