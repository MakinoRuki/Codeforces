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
#define N 1005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int main() {
	cin>>n;
	vector<int> ans;
	ans.clear();
	int gd=1;
	while(n>1) {
		int tot=1;
		int x=n;
		for (int i = n-1; i >= 2; --i) {
			if (n/i>tot) {
				tot=n/i;
				x=i;
			}
		}
		for (int i = 1; i <= n-tot; ++i) {
			ans.push_back(gd);
		}
		gd *= x;
		n = tot;
	}
	ans.push_back(gd);
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d", ans[i]);
		if (i<ans.size()-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
