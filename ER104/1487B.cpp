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
#define M 21
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m;
ll n, k;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld", &n, &k);
		if (n%2==0) {
			ll res = k/n;
			ll r = k%n;
			if (r==0) printf("%lld\n", n);
			else printf("%lld\n", r);
		} else {
			ll q = (k-1)/(n/2);
			if (q % 2 == 0) {
				ll st = q/2+1;
				ll r = (k-1)%(n/2);
			//	if (r == 0) r = n/2;
				st += r;
				st %= n;
				if (st==0) st = n;
				printf("%lld\n", st);
			} else {
				ll st = n/2+2+q/2;
				ll r = (k-1)%(n/2);
			//	if (r==0) r= n/2;
				st += r;
				st %= n;
				if (st == 0) st = n;
				printf("%lld\n", st);
			}
		}
	}
  return 0;
}
