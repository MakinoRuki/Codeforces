#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n;
ll u;
ll e[N];
int main() {
	cin>>n>>u;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &e[i]);
	}
	ll x = -1, y = -1;
	int j = 1;
	for (int i = 1; i <= n; ++i) {
		while(j <= n && e[j]-e[i]<=u) {
			j++;
		}
		j--;
		if (i+1<j) {
			ll det1=e[j]-e[i+1];
			ll det2=e[j]-e[i];
			if (x < 0 || x*det2<y*det1) {
				x=det1;
				y=det2;
			}
		}
	}
	if (x < 0) {
		puts("-1");
		return 0;
	}
	double ans = (double)x / (double)y;
	printf("%.10lf\n", ans);
	return 0;
}
