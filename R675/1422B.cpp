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
#include <queue>
#include <cmath>
#define N 200
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m;
int a[N][N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d",&n,&m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		ll tot=0LL;
		for (int i = 0; i < (n+1)/2; ++i) {
			for (int j = 0; j < (m+1)/2; ++j) {
				vector<int> rk;
				rk.clear();
				rk.push_back(a[i][j]);
				if (m-1-j != j) {
					rk.push_back(a[i][m-1-j]);
				}
				if (n-1-i != i) {
					rk.push_back(a[n-1-i][j]);
				}
				if (n-1-i != i && m-1-j != j) {
					rk.push_back(a[n-1-i][m-1-j]);
				}
				sort(rk.begin(), rk.end());
				ll minv=-1;
				for (int k=0;k<rk.size(); ++k) {
					ll det=0LL;
					for (int k1=0;k1<rk.size(); ++k1) {
						det += abs(rk[k1]-rk[k]);
					}
					if (minv<0 || minv>det) {
						minv=det;
					}
				}
				tot += minv;
			}
		}
		printf("%lld\n", tot);
	}
	return 0;
}
