#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 1000005
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n,m;
		scanf("%d%d", &n, &m);
		if (n == 1 && m==1) {
			puts("0");
			continue;
		}
		if (n == 1) {
			printf("%d\n", (m/3)+(m%3>0?1:0));
			continue;
		} 
		if (m == 1) {
			printf("%d\n", (n/3)+(n%3>0?1:0));
			continue;
		}
		ll ans= (ll)n*(ll)m+1;
		// ll tmp1 = n/3;
		// if (n%3 >0) tmp1++;
		// tmp1 *= m;
		// ll tmp2 = m/3;
		// if (m%3>0) tmp2++;
		// tmp2 *= n;
		// ans = min(tmp1, tmp2);
		for (int i = 0; i <= m; ++i) {
			if (i == m-1) continue;
			ll tmp = (ll)((n/3) + (n%3>0?1:0)) * (ll)i;
			tmp += (ll)(((m-i)/3) + ((m-i)%3>0?1:0)) * (ll)n;
			ans = min(ans, tmp);
		}
		for (int i = 0; i <= n; ++i) {
			if (i == n-1) continue;
			ll tmp = (ll)((m/3) + (m%3>0?1:0)) * (ll)i;
			tmp += (ll)(((n-i)/3) + ((n-i)%3>0?1:0)) * (ll)m;
			ans = min(ans, tmp);
		}
		printf("%lld\n", ans);
	}
  return 0;
}
