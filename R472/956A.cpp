#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <deque>
#include <cmath>
#define N 200
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, m;
vector<string> mat;
int par[N];
int find(int x) {
	return x==par[x] ? x : par[x] = find(par[x]);
}
int main() {
	cin>>n>>m;
	mat.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
	}
	for (int i = 0; i < n+m; ++i) {
		par[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == '#') {
				int px = find(i);
				int py = find(n+j);
				if (px != py) {
					par[px] = py;
				}
			}
		}
	}
	// for (int i = 0; i < n+m; ++i) {
	// 	cout<<i<<" "<<find(i)<<endl;
	// }
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int px = find(i);
			int py = find(n+j);
			if (px != py && mat[i][j] == '#') {
				ok=false;
				break;
			}
			if (px == py && mat[i][j] == '.') {
				ok=false;
				break;
			}
		}
		if (!ok) break;
	}
	if (ok) puts("Yes");
	else puts("No");
	return 0;
}
