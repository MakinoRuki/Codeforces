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
#define M 31
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<string> sv;
int cnt[N][2];
int main() {
	cin>>n;
	sv.clear();
	int cnt0=0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		sv.push_back(s);
		vector<char> stk;
		stk.clear();
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == ')') {
				if (!stk.empty() && stk.back()=='(') {
					stk.pop_back();
				} else {
					stk.push_back(s[j]);
				}
			} else {
				stk.push_back(s[j]);
			}
		}
		if (stk.empty()) {
			cnt0++;
			continue;
		}
		if (stk.size() > 1 && stk[0] != stk.back()) {
			continue;
		}
		if (stk.back() == '(') {
			cnt[(int)stk.size()][0]++;
		} else {
			cnt[(int)stk.size()][1]++;
		}
	}
	int ans=cnt0/2;
	for (int i = 1; i <= 500000; ++i) {
		ans += min(cnt[i][0], cnt[i][1]);
	}
	cout<<ans<<endl;
	return 0;
}
