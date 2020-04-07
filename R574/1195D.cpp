#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
ll a[N];
ll pw[21];
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	memset(pw, 0, sizeof(pw));
	pw[0] = 1LL;
	for (int i = 1; i <= 20; ++i) {
		pw[i] = pw[i-1]*10LL%mod;
	}
	int cnt[11];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		ll x = a[i];
		int num=0;
		while(x) {
			num++;
			x /= 10;
		}
		cnt[num]++;
	}
	ll ans = 0LL;
	for (int i = 0; i < n; ++i) {
	//	cout<<i<<" "<<a[i]<<endl;
		vector<int> ds;
		ll x = a[i];
		while(x) {
			ds.push_back(x%10);
			x/=10;
		}
		for (int j = 0; j < ds.size(); ++j) {
			for (int k = 1; k <= 10; ++k) {
				if (!cnt[k]) continue;
			//	cout<<"k="<<k<<" "<<cnt[k]<<endl;
				if (k >= ds.size()) {
					ans = (ans + ds[j]*pw[2*j+1]%mod*cnt[k]%mod) % mod;
					ans = (ans + ds[j]*pw[2*j]%mod*cnt[k]%mod) % mod;
				} else {
					if (j >= k) {
						ans = (ans + ds[j]*pw[j+k]%mod*cnt[k]%mod) % mod;
						ans = (ans + ds[j]*pw[j+k]%mod*cnt[k]%mod) % mod;
					} else {
						ans = (ans + ds[j]*pw[2*j+1]%mod*cnt[k]%mod) % mod;
						ans = (ans + ds[j]*pw[2*j]%mod*cnt[k]%mod) % mod;
					}
				}
				// if (k >= j+1) {
				// 	ans = (ans + ds[j]*pw[2*i+1]%mod*cnt[k]%mod) % mod;
				// 	ans = (ans + ds[j]*pw[2*i]%mod*cnt[k]%mod) % mod;
				// } else {
				// 	ans = (ans + ds[j]*pw[j+k]%mod*cnt[k]%mod) % mod;
				// }
			}
		} 
		//cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
