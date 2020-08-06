#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>s;
		set<int> id010, id011, id100, id101;
		id010.clear();
		id011.clear();
		id100.clear();
		id101.clear();
		vector<int> ans;
		ans.clear();
		int cnt=0;
		for (int i = 0; i < n; ++i) {
			if (s[i]=='0') {
				if (!id011.empty()) {
					auto id = *id011.begin();
					id011.erase(id);
					ans.push_back(id);
					id010.insert(id);
				} else if (!id101.empty()) {
					auto id = *id101.begin();
					id101.erase(id);
					ans.push_back(id);
					id100.insert(id);
				} else {
					id010.insert(++cnt);
					ans.push_back(cnt);
				}
			} else {
				if (!id010.empty()) {
					auto id = *id010.begin();
					id010.erase(id);
					ans.push_back(id);
					id011.insert(id);
				} else if (!id100.empty()) {
					auto id = *id100.begin();
					id100.erase(id);
					ans.push_back(id);
					id101.insert(id);
				} else {
					id101.insert(++cnt);
					ans.push_back(cnt);
				}
			}
		}
		printf("%d\n", cnt);
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d", ans[i]);
			if (i < ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
