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
#define N 100005
using namespace std;
typedef long long ll;
int q, n;
int x[N], y[N];
int f[N][5];
int n1[N], n3[N];
int n2[N], n4[N];
int main() {
	cin>>q;
	for (int c = 1; c <= q; ++c) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			for (int j = 1; j <= 4; ++j) {
				scanf("%d", &f[i][j]);
			}
		}
		vector<pair<int, int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			rk.push_back(make_pair(x[i], i));
		}
		sort(rk.begin(), rk.end());
		for (int i = 0; i <= n+2; ++i) {
			n1[i] = n2[i] = n3[i] = n4[i] = 0;
		}
		// memset(n1, 0, sizeof(n1));
		// memset(n2, 0, sizeof(n2));
		// memset(n3, 0, sizeof(n3));
		// memset(n4, 0, sizeof(n4));
		for (int i = 1; i <= n; ++i) {
			int id = rk[i-1].second;
			n3[i] = n3[i-1] + f[id][3];
		}
		for (int i = n; i >= 1; --i) {
			int id = rk[i-1].second;
			n1[i] = n1[i+1] + f[id][1];
		}
		int x0=-100005, y0 = -100005;
		int i=1;
		while(i <= n) {
			int j;
			for (j = i; j <= n; ++j) {
				if (rk[j-1].first != rk[i-1].first) break;
			}
			if (n3[i-1] == i-1 && n1[j] == n-j+1) {
				x0 = rk[i-1].first;
				break;
			}
			i = j;
		}
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			rk.push_back(make_pair(y[i], i));
		}
		sort(rk.begin(), rk.end());
		for (int i = 1; i <= n; ++i) {
			int id = rk[i-1].second;
			n2[i] = n2[i-1] + f[id][2];
		}
		for (int i = n; i >= 1; --i) {
			int id = rk[i-1].second;
			n4[i] = n4[i+1] + f[id][4];
		}
		i =1;
		while(i <= n) {
			int j;
			for (j = i; j <= n; ++j) {
				if (rk[j-1].first != rk[i-1].first) break;
			}
			if (n2[i-1] == i-1 && n4[j] == n-j+1) {
				y0 = rk[i-1].first;
				break;
			}
			i = j;
		}
		if (x0 < -100000 || y0 < -100000) {
			puts("0");
			continue;
		}
		printf("1 %d %d\n", x0, y0);
	}
	return 0;
}
