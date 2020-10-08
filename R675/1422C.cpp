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
#include <queue>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m;
string s;
ll pw[N];
ll pw2[N];
int main() {
	cin>>s;
	n=s.size();
	pw[0]=1LL;
	for (int i = 1; i <= n; ++i) {
		pw[i] = pw[i-1]*10LL%mod;
	}
	pw2[0]=0;
	for (int i =1 ; i <= n; ++i) {
		pw2[i] = (pw2[i-1]+(ll)i*pw[i-1]%mod)%mod;
	}
//	cout<<"x="<<pw2[2]<<endl;
	ll ans=0LL;
	for (int i = n-1; i >= 0; --i) {
		int det1=n-1-i;
		int det2=i;
		int d=s[i]-'0';
	//	cout<<"i="<<i<<" "<<d<<" "<<det1<<" "<<det2<<endl;
		ans = (ans + pw2[det1]*(ll)d%mod)%mod;
		ll x=(ll)i*(ll)(i+1)/2;
		x%=mod;
		ans = (ans + x*pw[det1]%mod*(ll)d%mod)%mod;
	}
	printf("%lld\n", ans);
	return 0;
}
