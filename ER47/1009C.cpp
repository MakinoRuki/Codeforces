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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int main() {
	cin>>n>>m;
	ll tot=0LL;
	ll s1=-1,s2=-1;
	for (int i = 1; i <= n; ++i) {
		ll d1 = (ll)i*(ll)(i-1)/2;
		ll d2 = (ll)(n-i)*(ll)(n-i+1)/2;
		if (s1 < 0) {
			s1=d1+d2;
		} else {
			if (d1+d2 < s1) {
				s1=d1+d2;
			}
		}
		if (s2 < 0) {
			s2 = d1+d2;
		} else {
			if (d1+d2>s2) {
				s2=d1+d2;
			}
		}
	}
	double ans = 0.0;
	while(m-->0) {
		int x,d;
		scanf("%d%d", &x, &d);
		ans += x;
		if (d < 0) {
			tot += (ll)d * s1;
		} else {
			tot += (ll)d * s2;
		}
	}
	ans += (double)tot/(double)n;
	printf("%.10lf\n", ans);
  return 0;
}
