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
#define M 10005
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s;
bool check(string& t, int len) {
	for (int i = 0; i + len <= n; ++i) {
		if (s.substr(i, len) == t) {
			return false;
		}
	}
	return true;
}
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		string t = "";
		string ans = "";
		for (int i = 0; i < 26; ++i) {
			t.push_back('a'+i);
			if (check(t, 1)) {
				ans = t;
				break;
			}
			t.pop_back();
		}
		if (!ans.empty()) {
			cout<<ans<<endl;
			continue;
		}
		for (int i = 0; i < 26; ++i) {
			t.push_back('a'+i);
			for (int j = 0; j < 26; ++j) {
				t.push_back(j+'a');
				if (check(t, 2)) {
					ans = t;
					break;
				}
				t.pop_back();
			}
			if (!ans.empty()) {
				break;
			}
			t.pop_back();
		}
		if (!ans.empty()) {
			cout<<ans<<endl;
			continue;
		}
		for (int i = 0; i < 26; ++i) {
			t.push_back('a'+i);
			for (int j = 0; j < 26; ++j) {
				t.push_back('a' + j);
				for (int k = 0; k < 26; ++k) {
					t.push_back('a' + k);
					if (check(t, 3)) {
						ans=t;
						break;
					}
					t.pop_back();
				}
				if (!ans.empty()) {
					break;
				}
				t.pop_back();
			}
			if (!ans.empty()) {
				break;
			}
			t.pop_back();
		}
		cout<<ans<<endl;
	}
  return 0;
}
