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
int a[N];
int b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n,m;
		scanf("%d", &n);
		printf("? %d %d\n", 1, n);
		fflush(stdout);
		ll tot;
		scanf("%lld", &tot);
		int l = 1, r = n;
		while(l < r) {
			int mid=(l+r+1)/2;
			printf("? %d %d\n", 1, mid);
			fflush(stdout);
			ll res;
			scanf("%lld", &res);
			if (res > 0) {
				r = mid-1;
			} else {
				l = mid;
			}
		}
		printf("? %d %d\n", r+1, n);
		fflush(stdout);
		ll res;
		scanf("%lld", &res);
		ll x = tot - res +1;
		ll tot2 = tot - (x*(x-1))/2;
	//	cout<<"tot2="<<tot2<<endl;
		ll l1 = 1LL, r1 = n;
		while(l1 < r1) {
			ll mid = (l1+r1+1)/2;
			if (mid - 1 <= (2LL*tot2)/mid) {
				l1 = mid;
			} else {
				r1 = mid-1;
			}
		}
		ll y = r1;
	//	cout<<x<<" "<<y<<endl;
		printf("! %d %lld %lld\n", r, r+x, r+x+y-1);
		fflush(stdout);
	}
  return 0;
}
