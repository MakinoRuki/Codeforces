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
int n, k;
int t;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		ll tot=0LL;
		for (int i =1 ; i <= n; ++i) {
			tot += a[i];
		}
		ll r = tot%(n-1);
		ll minv = (ll)a[n]*(ll)(n-1);
		if (tot<=minv) {
			printf("%lld\n", minv-tot);
		} else {
			if (r>0) {
				printf("%lld\n", (n-1)-r);
			} else {
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
