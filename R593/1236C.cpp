#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 305
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int main() {
	cin>>n;
	vector<vector<int>> ans(n);
	for (int i = 1; i <= n; ++i) {
		if (i & 1) {
			for (int j = 0; j < n; ++j) {
				ans[j].push_back((i-1)*n+j+1);
			}
		} else {
			for (int j= n-1; j>= 0; --j) {
				ans[j].push_back((i-1)*n+n-j);
			}
		}
	}
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout<<ans[i][j];
			if (j < ans[i].size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
