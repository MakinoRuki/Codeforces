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
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
int t;
int a[N];
int cnt[40];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i <= 32; ++i) {
			cnt[i]=0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			for (int j = 30; j >= 0; --j) {
				if ((1LL<<j) & a[i]) {
					cnt[j]++;
					break;
				}
			}
		}
		ll tot=0LL;
		for (int i = 0; i <= 30; ++i) {
		//	cout<<i<<" "<<cnt[i]<<endl;
			ll num=cnt[i];
			if (num<=0) continue;
			tot += num*(num-1)/2;
		}
		printf("%lld\n", tot);
	}
	return 0;
}
