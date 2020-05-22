#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 10005
using namespace std;
int n, m;
vector<int> ds[N];
int main() {
	cin>>m>>n;
	for (int i = 1; i <= m; ++i) {
		int s;
		scanf("%d", &s);
		for (int j = 1; j <= s;  ++j) {
			int x;
			scanf("%d", &x);
			ds[x].push_back(i);
		}
	}
	bool mat[52][52];
	memset(mat, false, sizeof(mat));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < ds[i].size(); ++j) {
			for (int k = j+1; k < ds[i].size(); ++k) {
				int d1 = ds[i][j];
				int d2 = ds[i][k];
				mat[d1][d2] = mat[d2][d1] = true;
			}
		}
	}
	bool ok = true;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i!=j && !mat[i][j]) ok = false;
		}
	}
	if (ok) cout<<"possible"<<endl;
	else cout<<"impossible"<<endl;
	return 0;
}
