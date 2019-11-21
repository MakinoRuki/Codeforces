#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 1000005
using namespace std;
typedef long long ll;
int n;
int a[N];
int main() {
	cin>>n;
	ll tot=0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		tot+=a[i];
	}
	ll ans = 1LL<<62;
	vector<ll> ps;
	for (ll i = 2; i * i <= tot; ++i) {
		if (tot % i == 0) {
			ps.push_back(i);
			while(tot % i == 0) tot /= i;
		}
	}
	if (tot > 1) ps.push_back(tot);
	// 考虑前缀和，1)如果每个ai都会%k=0则所有前缀和%k=0; 2)移动一个1相当于只有某一个前缀和+1/-1。
	for (auto p : ps) {
		ll val=0;
		ll cur=0;
		for (int i = 0; i < n; ++i) {
			// val += a[i];
			// if (val > 0) {
			// 	val %= p;
			// 	if (val < p-val) {
			// 		cur += val;
			// 	} else {
			// 		cur += p-val;
			// 		val = val-p;
			// 	}
			// } else {
			// 	int tmp = abs(val) % p;
			// 	if (tmp < p-tmp) {
			// 		cur += tmp;
			// 		val = -tmp;
			// 	} else {
			// 		cur += p-tmp;
			// 		val = p-tmp;
			// 	}
			// }
			val = (val + a[i]) % p;
			cur += min(val, p-val);
		}
		ans = min(ans, cur);
	}
	cout<<(ans < (1LL<<62) ? ans : -1)<<endl;
	return 0;
}
