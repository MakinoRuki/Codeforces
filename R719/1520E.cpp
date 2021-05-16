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
#define M 52
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
string s;
int lc[N], rc[N];
ll ls[N], rs[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		for (int i = 0; i <= n+1; ++i) {
			lc[i] = 0, rc[i] = 0;
			ls[i] = 0, rs[i] = 0;
		}
		ll ans = -1;
		for (int i = 1; i <= n; ++i) {
			lc[i] = lc[i-1];
			ls[i] = ls[i-1];
			if (s[i-1] == '*') {
				lc[i]++;
				ls[i] += (ll)i;
			}
		}
		for (int i = n; i >= 1; --i) {
			rc[i] = rc[i+1];
			rs[i] = rs[i+1];
			if (s[i-1] == '*') {
				rc[i]++;
				rs[i] += (ll)i;
			}
		}
		if (lc[n] == 0) {
			puts("0");
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			ll res=0LL;
			if (lc[i] > 0) {
				res = (ll)i*(ll)lc[i]-(ll)lc[i]*(ll)(lc[i]-1)/2LL-ls[i];
				if (rc[i+1]>0) {
					res += rs[i+1]-(ll)rc[i+1]*(ll)i-(ll)rc[i+1]*(ll)(rc[i+1]+1)/2LL;
				}
			//	cout<<i<<" "<<res<<endl;
				if (ans < 0 || ans > res) ans = res;
			//	if (i == 2) cout<<lc[i]<<" "<<ls[i]<<" "<<rs[i+1]<<" "<<rc[i+1]<<" "<<res<<endl;
			}
		//	if (i == 3) cout<<"x="<<ans<<endl;
			if (s[i-1] == '.' && rc[i] > 0) {
				res = rs[i] - (ll)((ll)rc[i]*(ll)i+(ll)rc[i]*(ll)(rc[i]-1)/2LL);
				if (lc[i-1]>0) {
					res += (ll)((ll)i*(ll)lc[i-1]-(ll)lc[i-1]*(ll)(lc[i-1]+1)/2LL) - ls[i-1];
				}
			//	cout<<i<<" "<<res<<endl;
				if (ans < 0 || ans > res) ans = res;
			}
		//	if (i == 3) cout<<"x="<<ans<<endl;
			//cout<<i<<" "<<ans<<endl;
		}
		printf("%lld\n", ans);
	}
  return 0;
}
