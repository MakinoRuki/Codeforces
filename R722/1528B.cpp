#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define N 1000005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int t, n;
int pr[2*N];
ll cnt[2*N];
ll dp[N];
int main() {
	memset(pr, -1, sizeof(pr));
	for (int i = 2; i * i < 2*N; ++i) {
		if (pr[i] < 0) {
			for (int j = i*i; j < 2*N; j += i) {
				pr[j] = i;
			}
		}
	}
//	cout<<"ok1"<<endl;
	memset(cnt, 0LL, sizeof(cnt));
	cnt[1] = 1;
	for (int i = 2; i < 2*N; ++i) {
		int p = pr[i];
		if (pr[i] < 0) {
			if (i == 2) cnt[i] = 1;
			else cnt[i] = 2;
			continue;
		}
		int cc = 0;
		int x= i;
	//	cout<<x<<" "<<p<<endl;
		while(x%p == 0) {
			cc++;
			x/=p;
		}
		if (p == 2) {
			cnt[i] = (ll)cc*cnt[x];
		} else {
			cnt[i] = (ll)(cc+1)*cnt[x];
		}
	}
//	cout<<"ok1"<<endl;
	cin>>n;
	dp[1] = 1;
	ll tot = dp[1];
	for (int i = 2; i <= n; ++i) {
		dp[i] = (tot + cnt[2*i]) % mod;
		tot = (tot + dp[i]) % mod;
	}
	cout<<dp[n]<<endl;
	return 0;
}
