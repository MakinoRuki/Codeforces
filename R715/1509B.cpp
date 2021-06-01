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
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		if (n%3 != 0) {
			puts("NO");
			continue;
		}
		vector<int> ts, ms;
		ts.clear();
		ms.clear();
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'T') {
				ts.push_back(i);
			} else {
				ms.push_back(i);
			}
		}
		bool ok = true;
		int mn = (int)ms.size();
		int tn = (int)ts.size();
		if (tn != mn * 2) {
			puts("NO");
			continue;
		}
		for (int i = 0; i < ms.size(); ++i) {
			if (ts[i] >= ms[i]) {
				ok=false;
				break;
			}
		}
		for (int i = 1; i <= tn/2; ++i) {
			if (ts[tn-i] <= ms[mn-i]) {
				ok=false;
				break;
			}
		}
		if (!ok) puts("NO");
		else puts("YES");
	}
  return 0;
}
