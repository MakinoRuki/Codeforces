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
#define N 205
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int a,b,c,d;
vector<string> ans;
int main() {
	cin>>a>>b>>c>>d;
	ans.clear();
	for (int i = 0; i < 12; ++i) {
		string s(50, 'A');
		ans.push_back(s);
	}
	for (int i = 12; i < 24; ++i) {
		string s(50, 'B');
		ans.push_back(s);
	}
	for (int i = 24; i < 36; ++i) {
		string s(50, 'C');
		ans.push_back(s);
	}
	for (int i = 36; i < 50; ++i) {
		string s(50, 'D');
		ans.push_back(s);
	}
	a--;
	b--;
	c--;
	d--;
	for (int i = 1; i < 12; i += 2) {
		for (int j = 0; j < 50; j += 2) {
			if (b) {
				ans[i][j]='B';
				b--;
			} else {
				break;
			}
		}
		if (!b) break;
	}
	for (int i = 13; i < 24; i += 2) {
		for (int j = 0; j < 50; j += 2) {
			if (a) {
				ans[i][j]='A';
				a--;
			} else {
				break;
			}
		}
		if (!a) break;
	}
	for (int i = 25; i < 36; i += 2) {
		for (int j = 0; j < 50; j += 2) {
			if (d) {
				ans[i][j]='D';
				d--;
			} else {
				break;
			}
		}
		if (!d) break;
	}
	for (int i = 37; i < 50; i += 2) {
		for (int j = 0; j < 50; j += 2) {
			if (c) {
				ans[i][j]='C';
				c--;
			} else {
				break;
			}
		}
		if (!c) break;
	}
	cout<<50<<" "<<50<<endl;
	for (int i = 0; i < 50; ++i) {
		cout<<ans[i]<<endl;
	}
	return 0;
}
