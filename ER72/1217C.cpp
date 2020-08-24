#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 105
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		ll ans = 0LL;
		int n = s.size();
		int pre = n;
		for (int i = n-1; i >= 0; --i) {
			if (s[i]=='1') {
				pre = i;
			}
			int j;
			if (pre < n) {
				ll res = 0LL;
				for (j = pre; j < n; ++j) {
					res = res*2LL+s[j]-'0';
					if (res == j-i+1) {
						ans++;
					}
					if (res > j-i+1) {
						break;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
