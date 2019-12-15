#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200020
#define inf 1000000000
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int t;
int main() {
	cin>>t;
	for (int cas = 0; cas <t; ++cas){ 
		int x;
		string s;
		cin>>x>>s;
		int n = s.size();
		ll ans = n % mod;
		for (int i= 1; i <= x; ++i) {
			ll det = (ans - i + mod) % mod;
			for (int k = 1; k <= s[i-1]-'0' - 1; ++k) {
				ans = (ans + det)%mod;
			}
			if (s.size() < 2 * x) {
				string ds = s.substr(i);
				for (int k= 1; k<=s[i-1]-'0'-1; ++k) {
					s += ds;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
