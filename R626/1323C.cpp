#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define N 40005
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int n;
string s;
bool check(int x, int y) {
	int tot=0;
	for (int i = x; i <= y; ++i) {
		if (s[i] == '(') tot++;
		else tot--;
		if (tot < 0) return false;
	}
	return true;
}
int main() {
	cin>>n>>s;
	int tot=0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			tot++;
		} else {
			tot--;
		}
	}
	if (tot != 0) {
		cout<<-1<<endl;
	} else {
		int st = 0;
		vector<pair<int, int>> segs;
		segs.clear();
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') tot++;
			else tot--;
			if (tot == 0) {
				segs.push_back(make_pair(st, i));
				st = i+1;
			}
		}
		int ans=0;
		for (int i = 0; i < segs.size(); ++i) {
			if (!check(segs[i].first, segs[i].second)) {
				ans += segs[i].second-segs[i].first+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
