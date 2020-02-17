#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#define N 300005
using namespace std;
typedef long long ll;
int n, m;
vector<int> pos[270];
int nums[N][9];
int main() {
	scanf("%d%d",&n,&m);
	int maxv = 0;
	for (int i = 1; i <= n; ++i) {
		//nums[i].clear();
		for (int j = 0; j < m; ++j) {
			scanf("%d", &nums[i][j]);
			maxv = max(maxv, nums[i][j]);
		}
	}
	int l = 0, r = maxv;
	while(l < r) {
		int mid = (l+r+1)/2;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		for (int i = 0; i < (1<<m); ++i) {
			pos[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			int s = 0;
			for (int j = 0; j < m; ++j) {
				if (nums[i][j] >= mid) {
					s |= (1<<j);
				}
			}
			pos[s].push_back(i);
		}
		bool ok = false;
		for (int s1 = 0; s1 < (1<<m); ++s1) {
			for (int s2 = 0; s2 < (1<<m); ++s2) {
				if ((s1 | s2) == ((1<<m)-1)) {
					if (pos[s1].size() > 0 && pos[s2].size() > 0) {
						ok = true;
						break;
					}
				}
			}
			if (ok) break;
		}
		if (ok) {
			l = mid;
		} else {
			r = mid-1;
		}
	}
	for (int i = 0; i < (1<<m); ++i) {
		pos[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		int s = 0;
		for (int j = 0; j < m; ++j) {
			if (nums[i][j] >= r) {
				s |= (1<<j);
			}
		}
		pos[s].push_back(i);
	}
	int s1, s2;
	for (s1 = 0; s1 < (1<<m); ++s1) {
		for (s2 = 0; s2 < (1<<m); ++s2) {
			if ((s1 | s2) == ((1<<m)-1)) {
				if ((pos[s1].size() > 0) && (pos[s2].size() > 0)) {
					break;
				}
			}
		}
		if (s2 < (1<<m)) break;
	}
	printf("%d %d\n", pos[s1][0], pos[s2][0]);
	return 0;
}
