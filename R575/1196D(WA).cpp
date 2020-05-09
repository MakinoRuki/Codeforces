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
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int q, n, k;
string s;
int cnt[N][3];
int getres(int x, int y, int z, int i, int j1, int j2, int j3) {
	int t1 = (j1-i)/3;
	int t2=(j2-i)/3;
	int t3 =(j3-i)/3;
	int nx = cnt[i][x];
	if (j1<n) nx -= cnt[j1][x];
	int ny = cnt[i][y];
	if (j2 < n) ny -= cnt[j2][y];
	int nz = cnt[i][z];
	if (j3 < n) nz -= cnt[j3][z];
	return t1-nx + t2-ny + t3-nz;
}
int main() {
	cin>>q;
	for (int c = 1; c <= q; ++c) {
		scanf("%d%d", &n, &k);
		cin>>s;
		if (k==1) {
			cout<<0<<endl;
			continue;
		}
		if (k==2) {
			int i=0;
			for (i = 0; i +1 < n; ++i) {
				if (s[i]=='R' && s[i+1] == 'G') break;
				if (s[i] == 'G' && s[i+1] == 'B') break;
				if (s[i] == 'B' && s[i+1] == 'R') break;
			}
			if (i+1 >= n) {
				cout<<1<<endl;
			} else {
				cout<<0<<endl;
			}
			continue;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = n-1; i >= 0; --i) {
			if (i+2 <= n-1) {
				for (int j = 0; j < 2; ++j) {
					cnt[i][j] = cnt[i+2][j];
				}
			}
			if (s[i] == 'R') cnt[i][0]++;
			if (s[i] == 'G') cnt[i][1]++;
			if (s[i] == 'B') cnt[i][2]++;
		}
		int ans= n;
		for (int i = 0; i + k <= n; ++i) {
			int j1 = i+(k+2)/3*3;
			int j2 = i+1+(k-1+2)/3*3;
			int j3 = i+2+(k-2+2)/3*3;
			int res = getres(0, 1, 2, i, j1, j2, j3);
			res = min(res, getres(1,2,0,i,j1,j2,j3));
			res = min(res, getres(2,0,1,i, j1,j2,j3));
			ans =min(ans, res);
		}
		cout<<ans<<endl;
	}
	return 0;
}
