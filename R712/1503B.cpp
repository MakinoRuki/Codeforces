#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#include <time.h>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t,n;
vector<pair<int,int>> ids[2];
int main() {
	scanf("%d", &n);
	ids[0].clear();
	ids[1].clear();
	bool flag = false;
	for (int i = n; i >= 1; --i) {
		int x = i, y = 1;
		while(x <= n && y <= n) {
			if (!flag) ids[0].push_back(make_pair(x, y));
			else ids[1].push_back(make_pair(x, y));
			x++;
			y++;
		}
		flag = !flag;
	}
	for (int j = 2; j <= n; ++j) {
		int x = 1, y = j;
		while(x <= n && y <= n) {
			if (!flag) ids[0].push_back(make_pair(x, y));
			else ids[1].push_back(make_pair(x, y));
			x++;
			y++;
		}
		flag = !flag;
	}
	reverse(ids[0].begin(), ids[0].end());
	reverse(ids[1].begin(), ids[1].end());
	for (int i = 1; i <= n*n; ++i) {
		int a;
		scanf("%d", &a);
		if (a != 2) {
			if (ids[1].size() > 0) {
				printf("2 %d %d\n", ids[1].back().first, ids[1].back().second);
				fflush(stdout);
				ids[1].pop_back();
			} else {
				if (a == 1) printf("3 %d %d\n", ids[0].back().first, ids[0].back().second);
				else printf("1 %d %d\n", ids[0].back().first, ids[0].back().second);
				fflush(stdout);
				ids[0].pop_back();
			}
		} else {
			if (ids[0].size() > 0) {
				printf("1 %d %d\n", ids[0].back().first, ids[0].back().second);
				fflush(stdout);
				ids[0].pop_back();
			} else {
				printf("3 %d %d\n", ids[1].back().first, ids[1].back().second);
				fflush(stdout);
				ids[1].pop_back();
			}
		}
	}
	return 0;
}
