#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 2005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int t, n, m;
vector<string> cells;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m;
		cells.clear();
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			cells.push_back(s);
		}
		vector<string> res(n, string(m, '.'));
		int r[2][26];
		int c[2][26];
		memset(r, -1, sizeof(r));
		memset(c, -1, sizeof(c));
		// cout<<r[0][1]<<" "<<r[1][1]<<endl;
		// cout<<c[0][1]<<" "<<c[1][1]<<endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (cells[i][j] == '.') continue;
				int x = cells[i][j]-'a';
			//	if (x==1) cout<<i<<" "<<j<<" "<<c[0][x]<<" "<<c[1][x]<<endl;
				if (r[0][x]<0) {
					r[0][x] = i;
					r[1][x] = i;
				} else {
					r[0][x] = min(r[0][x], i);
					r[1][x] = max(r[1][x], i);
				}
				if (c[0][x] < 0) {
					c[0][x] = j;
					c[1][x] = j;
				} else {
					c[0][x] = min(c[0][x], j);
					c[1][x] = max(c[1][x], j);
				}
				//if (x == 1) cout<<i<<" "<<j<<" "<<c[0][x]<<" "<<c[1][x]<<endl;
			}
		}
		for (int x = 0; x < 26; ++x) {
			if (r[0][x] >= 0) {
			//	cout<<x<<" "<<r[0][x]<<" "<<r[1][x]<<" "<<c[0][x]<<" "<<c[1][x]<<endl;
				if (r[0][x] == r[1][x]) {
					for (int j = c[0][x]; j <= c[1][x]; ++j) {
						res[r[0][x]][j] = 'a' + x;
					}
				} else if (c[0][x] == c[1][x]) {
					for (int i = r[0][x]; i <= r[1][x]; ++i) {
						res[i][c[0][x]] = 'a'+x;
					}
				} else {
					break;
				}
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (res[i][j] == cells[i][j]) continue;
				ok = false;
				break;
			}
			if (!ok) break;
		}
		if (!ok) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			int pre=-1;
			for (int x = 25; x >= 0; --x) {
			//	cout<<x<<" "<<r[0][x]<<" "<<r[1][x]<<endl;
				if (r[0][x] < 0) {
					if (pre >= 0) {
						r[0][x] = r[0][pre];
						r[1][x] = r[0][pre];
						c[0][x] = c[0][pre];
						c[1][x] = c[0][pre];
					}
				} else {
					pre = x;
				}
			}
			int x;
			for (x=0;x < 26; ++x) {
				if (r[0][x] < 0) break;
			}
			cout<<x<<endl;
			for (int i = 0; i < x; ++i) {
				cout<<r[0][i]+1<<" "<<c[0][i]+1<<" "<<r[1][i]+1<<" "<<c[1][i]+1<<endl;
			}
		}
	}
	return 0;
}
