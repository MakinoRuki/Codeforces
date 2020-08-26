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
#define N 55
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int n, m;
int ma[N][N];
bool check(int i, int j) {
	for (int x = 0; x < 2; ++x) {
		for (int y = 0; y < 2; ++y) {
			if (i+x>=1 && i+x<=n && j+y>=1 && j+y<=m) {
				if (!ma[i+x][j+y]) return false;
			} else {
				return false;
			}
		}
	}
	return true;
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &ma[i][j]);
		}
	}
	set<pair<int,int>> ss;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (ma[i][j]) {
				bool ok = false;
				if (check(i-1,j-1)) {
					ok = true;
					ss.insert(make_pair(i-1,j-1));
				}
				if (check(i-1,j)) {
					ok = true;
					ss.insert(make_pair(i-1,j));
				}
				if (check(i,j-1)) {
					ok = true;
					ss.insert(make_pair(i,j-1));
				}
				if (check(i,j)) {
					ok = true;
					ss.insert(make_pair(i,j));
				}
				if (!ok) {
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	cout<<(int)ss.size()<<endl;
	for (auto pr : ss) {
		printf("%d %d\n", pr.first, pr.second);
	}
	return 0;
}
