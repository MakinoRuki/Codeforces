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
#define M 25
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
ll c[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &c[i]);
		}
		ll ans=0;
		ll n1=1,n2=1;
		ll m1 = c[1];
		ll m2 = c[2];
		ll s1 = c[1];
		ll s2 = c[2];
		ans = m1*(n-n1+1)+(s1-m1) + m2*(n-n2+1)+(s2-m2);
		for (int i = 3; i <= n; ++i) {
			if (i%2) {
				n1++;
				m1 = min(m1, c[i]);
				s1 += c[i];
			} else {
				n2++;
				m2 = min(m2, c[i]);
				s2 += c[i];
			}
			ans = min(ans, m1*(n-n1+1)+(s1-m1) + m2*(n-n2+1)+(s2-m2));
		}
		printf("%lld\n", ans);
	}
  return 0;
}
