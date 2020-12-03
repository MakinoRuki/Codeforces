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
#define M 20005
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,q;
int t;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		int n = s.size();
		vector<pair<int, char>> cnt(3);
		int rc=0;
		int pc=0;
		int sc=0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'R') {
				rc++;
			} else if (s[i] == 'P') {
				pc++;
			} else {
				sc++;
			}
		}
		cnt.push_back(make_pair(rc, 'R'));
		cnt.push_back(make_pair(pc, 'P'));
		cnt.push_back(make_pair(sc, 'S'));
		sort(cnt.begin(), cnt.end());
		reverse(cnt.begin(), cnt.end());
		string ans="";
		if (cnt[0].second == 'R') {
			ans = string(n, 'P');
		} else if (cnt[0].second == 'P') {
			ans = string(n, 'S');
		} else {
			ans = string(n, 'R');
		}
		cout<<ans<<endl;
	}
	return 0;
}
