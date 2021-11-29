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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int a[N];
int cnt[35];
ll getpw(ll x, ll y) {
	ll res=1LL;
	while(y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
int main() {
	cin>>n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		int num=0;
		while(a[i] % 2 == 0) {
			num++;
			a[i]/=2;
		}
		cnt[num]++;
	}
	for (int i = 30; i >= 0; --i) {
		cnt[i] += cnt[i+1];
	}
	ll ans = 0LL;
	for (int i = 0; i <= 30; ++i) {
		ll res = 0LL;
		if (i == 0) {
			if (cnt[i]-cnt[i+1] == 0) {
				continue;
			}
			res = (getpw(2LL, cnt[i]-cnt[i+1]) - 1 + mod) % mod;
			res = res * getpw(2LL, n- (cnt[i]-cnt[i+1])) % mod;
		} else {
			if (cnt[i] - cnt[i+1] < 2) continue;
			res = (getpw(2LL, cnt[i]-1) - getpw(2LL, cnt[i+1]) + mod) % mod;
		}
		ans = (ans + res) % mod;
	}
	// ll ans2 = (getpw(2, n) - getpw(2, (int)es.size()) + mod) % mod;
	// cout<<"x="<<ans2<<endl;
	// ans = (ans + ans2) % mod;
	cout<<ans<<endl;
  return 0;
}

