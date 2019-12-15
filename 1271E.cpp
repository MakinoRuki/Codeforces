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
int a,b,c,d,e,f;
typedef long long ll;
ll n, k;
ll getcnt(ll x) {
	ll add = 1;
	ll cnt=0;
	if (x & 1) {
		if (x <= n) cnt++;
	} else {
		if (x <= n) cnt++;
		if (x+1>0&&x + 1 <= n) cnt++;
	}
	if (!(x&1)) add = add*2+1;
	x *= 2;
	while(true) {
		if (x > n || x < 0) break;
		ll det = min(n-x, add);
		if (det <= 0) break;
		cnt += det+1;
		x *= 2;
		add = add*2+1;
	}
	//if (x == (1LL<<59)+(1LL<<58)+(1LL<<56)) cout<<"???cnt="<<cnt<<endl;
	return cnt;
}
int main() {
	cin>>n>>k;
	ll ans=0;
  // 答案一定是一个前缀。枚举这个前缀的最大的2的幂次，然后后面的位一位一位枚举是否可以为1。
  // getcnt(x)求出当前前缀有多少条path。
	for (int i = 62; i >= 0; --i) {
		ll res=1LL<<i;
		if (res < 0 || res > n) continue;
		for (int j = i-1; j >= 0; --j) {
			ll tmp = res+(1LL<<j);
			if (tmp > n || tmp < 0) continue;
			//if (i ==59)cout<<"!j="<<j<<endl;
		//	if (tmp == 1000000000000000000LL) cout<<"???"<<endl;
			ll cnt = getcnt(tmp);
			if (cnt >= k) {
				//if (i == 59) cout<<"j="<<j<<endl;
				res += 1LL<<j;
			}
		}
		ll cnt = getcnt(res);
		if (cnt >= k)
		ans = max(ans, res);
	}
	cout<<ans<<endl;
	return 0;
}
