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
#define M 20005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
ll getgcd(ll x, ll y) {
	return y==0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		ll p, q, b;
		scanf("%lld%lld%lld", &p, &q, &b);
		if (p%q==0) {
			puts("Finite");
		} else {
			p %= q;
			ll gcd = getgcd(p ,q);
			p /= gcd;
			q /= gcd;
			while(q%b==0) {
				q/=b;
			}
			while(true) {
				gcd=getgcd(b, q);
				if (gcd == 1) {
					break;
				}
				while(q%gcd == 0) {
					q/=gcd;
				}
			}
			if (q == 1) {
				puts("Finite");
			} else {
				puts("Infinite");
			}
		}
	}
	return 0;
}
