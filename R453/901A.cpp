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
#define N 200010
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, m;
int h;
int a[N];
void solve(int lev, int f) {
	int cnt=0;
	vector<pair<int,int>> v[N];
	for (int i = 0; i <= h; ++i) {
		for (int j = 1; j <= a[i]; ++j) {
			++cnt;
			if (i-1 == lev) {
				if (!f) v[i].push_back(make_pair(cnt, v[i-1][0].first));
				else {
					if (j == 1) v[i].push_back(make_pair(cnt, v[i-1][0].first));
					else v[i].push_back(make_pair(cnt, v[i-1][1].first));
				}
			} else {
				if (i > 0) {
					v[i].push_back(make_pair(cnt, v[i-1][0].first));
				} else {
					v[i].push_back(make_pair(cnt, 0));
				}
			}
		}
	}
	int tot=0;
	for (int i = 0; i <= h; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			printf("%d", v[i][j].second);
			tot++;
			if (tot < cnt) cout<<" ";
			else cout<<endl;
		}
	}
}
int main() {
	cin>>h;
	for (int i = 0; i <= h; ++i) {
		scanf("%d", &a[i]);
	}
	int lev = -1;
	int cnt=0;
	for (int i = 0; i <= h; ++i) {
		if (a[i] > 1) {
			if (i == 0 || a[i-1] <= 1) {
				lev = i;
				cnt = 1;
			} else {
				cnt++;
				break;
			}
		} else {
			lev = -1;
			cnt=0;
		}
	}
	if (lev < 0 || cnt == 1) {
		puts("perfect");
	} else {
		puts("ambiguous");
		solve(lev, 0);
		solve(lev, 1);
	}
	return 0;
}
