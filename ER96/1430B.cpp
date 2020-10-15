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
int t,n,k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n,&k);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		ll tot=0LL;
		for (int i = 0; i <= k; ++i) {
			tot += a[n-i];
		}
		printf("%lld\n", tot);
	}
	return 0;
}
