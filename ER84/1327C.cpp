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
#define N 100005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m, k;
int main() {
	cin>>n>>m>>k;
	for (int i = 1; i <= k; ++i) {
		int sx, sy;
		scanf("%d%d", &sx,&sy);
	}
	for (int i = 1; i <= k; ++i) {
		int fx, fy;
		scanf("%d%d", &fx, &fy);
	}
	printf("%d\n", 2*n*m-2);
	string ans="";
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (i&1) ans += "R";
			else ans += "L";
		}
		if (i < n) ans += "D";
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (i&1) {
				if (n&1) ans += "L";
				else ans += "R";
			} else {
				if (n&1) ans += "R";
				else ans += "L";
			}
		}
		if (i < n) ans += "U";
	}
	cout<<ans<<endl;
  return 0;
}
