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
#define N 52
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int main() {
	cin>>s;
	vector<pair<int, int>> ans;
	ans.clear();
	bool row = false;
	bool col = false;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			if (col) {
				ans.push_back(make_pair(3, 1));
			} else {
				ans.push_back(make_pair(1, 1));
			}
			col = !col;
		} else {
			if (row) {
				ans.push_back(make_pair(4, 1));
			} else {
				ans.push_back(make_pair(4, 3));
			}
			row = !row;
		}
	}
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
  return 0;
}
