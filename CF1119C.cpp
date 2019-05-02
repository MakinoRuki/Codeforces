#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 502
using namespace std;
typedef long long ll;
int n,m;
//ll h;
int a[N][N];
int b[N][N];
int main() {
	cin>>n>>m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin>>a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin>>b[i][j];
		}
	}
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		int cnt=0;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != b[i][j]) {
				cnt++;
			}
		}
		if (cnt&1) {
			ok=false;
			break;
		}
	}
	for (int j = 0; j < m; ++j) {
		int cnt=0;
		for (int i = 0;i< n; ++i) {
			if (a[i][j] != b[i][j])cnt++;
		}
		if (cnt&1) {
			ok = false;
			break;
		}
	}
	cout<<(ok?"Yes":"No")<<endl;
	return 0;
}
