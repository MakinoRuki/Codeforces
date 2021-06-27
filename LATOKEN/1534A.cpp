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
#define M 10005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
vector<string> mat;
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d%d", &n, &m);
		mat.clear();
		int r = -1, w = -1;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
			for (int j = 0; j < m; ++j) {
				int x = (i+j)%2;
				if (mat[i][j] == 'R') {
					if (r >= 0 && r != x) {
						ok=false;
					} else {
						r = x;
					}
				} else if (mat[i][j] == 'W') {
					if (w >= 0 && w != x) {
						ok=false;
					} else {
						w = x;
					}
				}
			}
		}
		if (r < 0 && w < 0) {
			r = 0, w = 1;
		} else if (r < 0) {
			r = !w;
		} else if (w < 0) {
			w = !r;
		}
		if (!ok || (r == w)) puts("NO");
		else {
			puts("YES");
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					int x = (i+j)%2;
					if (mat[i][j] == '.' && x == r) {
						mat[i][j] = 'R';
					} else if (mat[i][j] == '.' && x == w) {
						mat[i][j] = 'W';
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				cout<<mat[i]<<endl;
			}
		}
	}
  return 0;
}
