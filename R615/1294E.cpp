#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int mat[N];
int main() {
	cin>>n>>m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin>>mat[i*m+j];
		}
	}
	int ans=0;
	for (int j = 0; j < m; ++j) {
		vector<int> sft(n, 0);
		for (int i = 0; i < n; ++i) {
			int det = mat[i*m+j] - (j+1);
			if (det >= 0 && (det % m == 0)) {
				int x = det / m;
				if (x >= 0 && x < n) {
					sft[(i-x+n) % n]--;
				}
			}
		}
		int minv = n + sft[0];
		for (int i = 1; i < n; ++i) {
			minv = min(minv, i + n + sft[i]);
		}
		ans += minv;
	}
	cout<<ans<<endl;
	return 0;
}
