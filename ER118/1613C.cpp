#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
string s;
int t;
int n, q, m, k, e;
ll a[N];
int getlen(int x) {
	int cnt=0;
	while(x) {
		cnt++;
		x/=10;
	}
	return cnt;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll h;
		scanf("%d%lld", &n, &h);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		ll l = 0, r = h;
		while(l < r) {
			ll mid = (l+r)/2;
			ll tot = 0LL;
			for (int i = 1; i <= n; ++i) {
				if (i == n) {
					if (tot >= h-mid) {
						tot = h;
						break;
					}
					tot += mid;
				} else {
					if (a[i+1] >= a[i] + mid) {
						if (tot >= h-mid) {
							tot = h;
							break;
						}
						tot += mid;
					} else {
						if (tot >= h- (a[i+1]-a[i])) {
							tot = h;
							break;
						}
						tot += a[i+1] - a[i];
					}
				}
			}
			if (tot < 0 || tot >= h) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		printf("%lld\n", r);
	}
  return 0;
}

