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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll a,b,c,d;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (b*c<a) {
			cout<<-1<<endl;
		} else {
			ll k = c/d;
			if (d*b>=a) {
				printf("%lld\n", a);
			} else {
				ll k2=a/(d*b);
				k2=min(k2, k);
				ll res=d*b*k2-2*a;
				res *= (k2+1);
				res /= 2;
				printf("%lld\n", abs(res));
			}
		}
	}
	return 0;
}
