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
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 20005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
vector<string> mat;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		mat.clear();
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
		}
		vector<pair<int,int>> ans;
		ans.clear();
		for (int x = 0; x < 2; ++x) {
			if (mat[0][1]-'0' != x) {
				ans.push_back(make_pair(0,1));
			}
			if (mat[1][0]-'0' != x) {
				ans.push_back(make_pair(1,0));
			}
			if (mat[0][2]-'0' != (!x)) {
				ans.push_back(make_pair(0,2));
			}
			if (mat[1][1]-'0' != (!x)) {
				ans.push_back(make_pair(1,1));
			}
			if (mat[2][0]-'0' != (!x)) {
				ans.push_back(make_pair(2,0));
			}
			if (ans.size()<=2) {
				break;
			}
			ans.clear();
		}
		int sz=(int)ans.size();
		printf("%d\n", sz);
		for (int i =0; i < sz; ++i) {
			printf("%d %d\n", ans[i].first+1, ans[i].second+1);
		}
	}
	return 0;
}
