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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 52
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
vector<string> ss;
int check(int i1, int i2, int i3) {
	int det = 0;
	int i;
	int tot=0;
	det = INT_MAX;
	for (i = 0; i < ss[i1].size(); ++i) {
		if (ss[i1][i] >= 'a' && ss[i1][i] <= 'z') {
			det = min(det, min(i, m-i));
		}
	}
	if (det >= INT_MAX) {
		return det;
	}
	tot += det;
	det = INT_MAX;
	for (i = 0; i < ss[i2].size(); ++i) {
		if (ss[i2][i] >= '0' && ss[i2][i] <= '9') {
			det = min(det, min(i, m-i));
		}
	}
	if (det >= INT_MAX) {
		return det;
	}
	tot += det;
	det = INT_MAX;
	for (i = 0; i < ss[i3].size(); ++i) {
		if (ss[i3][i] == '#' || ss[i3][i] == '*' || ss[i3][i] == '&') {
			det = min(det, min(i, m-i));
		}
	}
	if (det >= INT_MAX) {
		return det;
	}
	tot += det;
//	cout<<i1<<" "<<i2<<" "<<i3<<" "<<tot<<endl;
	return tot;
}
int main() {
	// cin>>t;
	// for (int cas=1; cas<=t; ++cas) {
	// }
	cin>>n>>m;
	ss.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		ss.push_back(s);
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (i == j || j == k || i == k) {
					continue;
				}
				ans = min(ans, check(i, j, k));
			}
		}
	}
	cout<<ans<<endl;
  return 0;
}
