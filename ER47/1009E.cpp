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
int n;
int a[N];
ll getpw(ll x, ll y) {
	ll res= 1LL;
	while(y) {
		if (y%2) res=res*x%mod2;
		x=x*x%mod2;
		y/=2;
	}
	return res;
}
int main() {
	cin>>n;
	ll tot=0LL;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		int cnt=n-i+1;
		ll cur=getpw(2LL, n-i);
		if (cnt-1>0) {
			cur = (cur + (ll)(cnt-1)*getpw(2LL, n-i-1) % mod2) % mod2;
		}
		tot = (tot + (ll)a[i] * cur % mod2) % mod2;
	}
	cout<<tot<<endl;
  return 0;
}
