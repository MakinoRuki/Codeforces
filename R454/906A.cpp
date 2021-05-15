#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, a, b;
bool vis[27];
int main() {
	cin>>n;
	int ans = 0;
	memset(vis, false, sizeof(vis));
	int id = -1;
	for (int i = 0; i < n; ++i) {
		string op, wd;
		cin>>op>>wd;
		if (op == "!") {
			set<int> ss;
			ss.clear();
			for (int j = 0; j < wd.size(); ++j) {
				int c = wd[j]-'a';
				ss.insert(c);
			}
			for (int j = 0; j < 26; ++j) {
				if (ss.find(j) == ss.end()) {
					vis[j] = true;
				}
			}
			if (id >= 0) {
				ans++;
			}
		} else if (op == ".") {
			for (int j = 0; j < wd.size(); ++j) {
				vis[wd[j]-'a'] = true;
			}
		} else {
			if (id >= 0 && wd[0]-'a' != id) {
				ans++;
			} else if (id < 0) {
				vis[wd[0]-'a'] = true;
			}
		}
		int cnt=0;
		for (int j = 0; j < 26; ++j) {
			if (!vis[j]) cnt++;
		}
		if (cnt==1) {
			for (int j = 0; j < 26; ++j) {
				if (!vis[j]) {
					id = j;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
