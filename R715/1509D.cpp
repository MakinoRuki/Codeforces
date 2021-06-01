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
#define M 25
#define N 2002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, q;
vector<string> sv;
string s;
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		sv.clear();
		vector<string> v0, v1;
		v0.clear();
		v1.clear();
		s.clear();
		for (int i = 0; i < 3; ++i) {
			cin>>s;
			sv.push_back(s);
			int cnt=0;
			for (int j = 0; j < 2*n; ++j) {
				if (s[j] == '1') cnt++;
			}
			if (cnt >= n) {
				v1.push_back(s);
			} else {
				v0.push_back(s);
			}
		}
		string ans = "";
		if (v1.size() >= 2) {
			int j = 0;
			int tot = 0;
			for (int i = 0; i < 2*n; ++i) {
				if (v1[1][i] == '1' && tot < n) {
					while(j < v1[0].size() && v1[0][j] != '1') {
						ans.push_back(v1[0][j]);
						j++;
					}
					ans.push_back(v1[0][j]);
					j++;
					tot++;
				} else if (v1[1][i] == '1') {
					ans.push_back('1');
				} else {
					ans.push_back('0');
				}
			}
			while(j < v1[0].size()) {
				ans.push_back(v1[0][j]);
				j++;
			}
		} else {
			int j = 0;
			int tot = 0;
			for (int i = 0; i < 2*n; ++i) {
				if (v0[1][i] == '0' && tot < n) {
					while(j < v0[0].size() && v0[0][j] != '0') {
						ans.push_back(v0[0][j]);
						j++;
					}
					ans.push_back(v0[0][j]);
					j++;
					tot++;
				} else if (v0[1][i] == '0') {
					ans.push_back('0');
				} else {
					ans.push_back('1');
				}
			}
			while(j < v0[0].size()) {
				ans.push_back(v0[0][j]);
				j++;
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}
