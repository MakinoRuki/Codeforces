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
#define N 100
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N], b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
		}
		int mina = a[1];
		int minb = b[1];
		for (int i = 1; i <= n; ++i) {
			mina = min(mina, a[i]);
		}
		for (int i =1; i <= n; ++i) {
			minb = min(minb, b[i]);
		}
		for (int i = 1; i <= n; ++i) {
			a[i] = a[i]-mina;
		}
		for (int i = 1; i <= n; ++i) {
			b[i] = b[i]-minb;
		}
		ll ans = 0LL;
		for (int i = 1; i <= n; ++i) {
			ans += (ll)max(a[i], b[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
