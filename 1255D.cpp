#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
int T;
int r,c,k;
char getch(int cnt) {
	if (cnt < 26) return 'a'+cnt;
	else if (cnt < 52) return 'A'+cnt-26;
	else return '0'+cnt-52;
}
int main() {
	cin>>T;
	for (int cas=1; cas<=T; ++cas) {
		cin>>r>>c>>k;
		vector<string> mat;
		int tot=0;
		for (int i = 0; i < r; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
			for (int j = 0; j < c; ++j) {
				if (mat[i][j] == 'R') tot++;
			}
		}
		vector<string> ans;
		for (int i = 0; i < r; ++i) {
			string s(c, ' ');
			ans.push_back(s);
		}
		int qq = tot/k;
		int rr = tot%k;
		int cnt=0;
		int x=0,y=0;
		int cur=0;
		while(x >= 0 && x < r && y >= 0 && y < c) {
			if (mat[x][y] == 'R') {
				if (cnt < rr) {
					if (cur<qq+1) {
						cur++;
						ans[x][y] = getch(cnt);
					} else {
						cnt++;
						cur=1;
						ans[x][y] = getch(cnt);
					}
				} else {
					if (cur < qq) {
						cur++;
						ans[x][y] = getch(cnt);
					} else {
						cnt++;
						cur=1;
						ans[x][y] = getch(cnt);
					}
				}
			} else {
				ans[x][y] = getch(cnt);
			}
			if (x % 2) {
				y--;
				if (y < 0) {
					x++;
					y=0;
				}
			} else {
				y++;
				if (y >= c) {
					x++;
					y = c-1;
				}
			}
		}
		for (int i = 0; i < r; ++i) {
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}
