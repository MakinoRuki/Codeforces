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
#define N 300005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
vector<pair<int,int>> s;
ll fac[N];
int main() {
	cin>>n;
	s.clear();
	vector<int> as;
	vector<int> bs;
	as.clear();
	bs.clear();
	memset(fac, 0LL, sizeof(fac));
	fac[0] = 1LL;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i-1]*(ll)i%mod2;
	}
	for (int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d%d", &a,&b);
		s.push_back(make_pair(a,b));
		as.push_back(a);
		bs.push_back(b);
	}
	ll ans = 1LL;
	for (int i = 1; i <= n; ++i) {
		ans = ans * (ll)i % mod2;
	}
	sort(as.begin(), as.end());
	ll res = 1LL;
	int cnt=0;
	for (int i = 0; i < as.size(); ++i) {
		if (i==0) {
			cnt++;
		} else {
			if (as[i] == as[i-1]) {
				cnt++;
			} else {
				if (cnt>1) {
					res = res * fac[cnt] % mod2;
				}
				cnt = 1;
			}
		}
	}
//	cout<<"cnt1="<<cnt<<endl;
	if (cnt>1) {
		res = res * fac[cnt] % mod2;
	}
//	cout<<"res1="<<res<<endl;
	ans= (ans-res+mod2) % mod2;
	sort(bs.begin(), bs.end());
	res = 1LL;
	cnt = 0;
	for (int i = 0; i < bs.size(); ++i) {
		if (i==0) {
			cnt++;
		} else {
			if (bs[i]==bs[i-1]) {
				cnt++;
			} else {
				if (cnt>1) {
					res = res*fac[cnt]%mod2;
				}
				cnt = 1;
			}
		}
	}
	if (cnt>1) {
		res = res*fac[cnt]%mod2;
	}
//	cout<<"res2="<<res<<endl;
	ans = (ans - res+mod2) % mod2;
	sort(s.begin(), s.end());
	res = 1LL;
	cnt=0;
	for (int i = 0; i < s.size(); ++i) {
		if (i == 0) {
			cnt=1;
		} else {
			if (s[i].first < s[i-1].first || s[i].second < s[i-1].second) {
				res = 0LL;
				break;
			}
			if (s[i] == s[i-1]) {
				cnt++;
			} else {
				if (cnt>1) {
					res=res*fac[cnt]%mod2;
				}
				cnt=1;
			}
		}
	}
	if (cnt>1) {
		res=res*fac[cnt]%mod2;
	}
//	cout<<"res3="<<res<<endl;
	ans=(ans+res)%mod2;
	printf("%lld\n", ans);
	return 0;
}
