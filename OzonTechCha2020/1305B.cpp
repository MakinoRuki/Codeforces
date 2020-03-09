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
#define N 102
using namespace std;
typedef long long ll;
string s;
int main() {
	cin>>s;
	int n = s.size();
	vector<vector<int>> ans;
	ans.clear();
	while(true) {
		vector<int> tmp;
		tmp.clear();
		int l = 0, r = s.size()-1;
		bool mark[1002];
		memset(mark, false, sizeof(mark));
		while(l < r) {
			int l1 = l;
			int r1 = r;
			while(l1 < r1 && s[l1] != '(') l1++;
			while(r1 > l1 && s[r1] != ')') r1--;
			if (l1 < r1) {
				tmp.push_back(l1+1);
				tmp.push_back(r1+1);
				mark[l1]=true;
				mark[r1] = true;
			} else {
				break;
			}
			l = l1+1;
			r = r1-1;
		}
		if (tmp.empty()) break;
		sort(tmp.begin(), tmp.end());
		ans.push_back(tmp);
		string t = "";
		for (int i = 0; i < s.size(); ++i) {
			if (!mark[i]) t.push_back(s[i]);
		}
		s = t;
	}
	cout<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout<<ans[i].size()<<endl;
		for (int j = 0; j < ans[i].size(); ++j) {
			cout<<ans[i][j];
			if (j < ans[i].size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
