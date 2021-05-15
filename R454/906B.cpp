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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, a, b, m;
vector<vector<int>> mat;
void revmat() {
	vector<vector<int>> mat2;
	mat2.clear();
	for (int j = 0; j < m; ++j) {
		mat2.push_back({});
		for (int i = 0; i < n; ++i) {
			mat2[j].push_back(mat[i][j]);
		}
	}
	mat = mat2;
}
int main() {
	cin>>n>>m;
	bool rev = false;
	mat.clear();
	for (int i = 1; i <= n; ++i) {
		vector<int> tmp;
		tmp.clear();
		for (int j = 1; j <= m; ++j) {
			tmp.push_back((i-1)*m+j);
		}
		mat.push_back(tmp);
	}
	if (n > m) {
		revmat();
		rev = true;
		swap(n, m);
	}
	if (n == 1 && m == 1) {
		puts("YES");
		cout<<1<<endl;
	} else if (n == 1 && (m==2 || m==3)) {
		puts("NO");
	} else if (n == 2 && (m==2 || m==3)) {
		puts("NO");
	} else if (n == 3 && m == 3) {
		puts("YES");
		cout<<6<<" "<<1<<" "<<8<<endl;
		cout<<7<<" "<<5<<" "<<3<<endl;
		cout<<2<<" "<<9<<" "<<4<<endl;
	} else {
		puts("YES");
		vector<vector<int>> ans;
		if (m > 4) {
			for (int i = 0; i < n; ++i) {
				ans.push_back({});
				for (int j = i%2; j < m; j += 2) {
					ans[i].push_back(mat[i][j]);
				}
				for (int j = 1 - i%2; j < m; j += 2) {
					ans[i].push_back(mat[i][j]);
				}
			}
		} else {
			for (int i = 0; i < n; ++i) {
				ans.push_back({});
				for (int j = 1; j < m; j += 2) {
					ans[i].push_back(mat[i][j]);
				//	cout<<i<<" "<<j<<" "<<ans[i].back()<<endl;
				}
				for (int j = 0; j < m; j += 2) {
					ans[i].push_back(mat[i][j]);
				//	cout<<i<<" "<<j<<" "<<ans[i].back()<<endl;
				}
				if (i % 2) reverse(ans[i].begin(), ans[i].end());
			}
		}
		mat = ans;
		if (rev) {
			revmat();
			swap(n, m);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%d", mat[i][j]);
				if (j < m-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
