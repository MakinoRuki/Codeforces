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
#define N 5002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int main() {
	scanf("%d", &n);
	if (n%4) {
		printf("! -1\n");
		return 0;
	}
	int l = 1, r = 1+n/2;
	printf("? %d\n", l);
	fflush(stdout);
	int v1, v2;
	scanf("%d", &v1);
	printf("? %d\n", r);
	fflush(stdout);
	scanf("%d", &v2);
	if (v1==v2) {
		printf("! 1\n");
		return 0;
	}
	ll lv = v1-v2;
	ll rv = v2-v1;
	while(l + 1 < r) {
		int mid=(l+r)/2;
		ll v1, v2;
		printf("? %d\n", mid);
		fflush(stdout);
		scanf("%lld", &v1);
		printf("? %d\n", mid+n/2);
		fflush(stdout);
		scanf("%lld", &v2);
		ll det=v1-v2;
		if (det == 0) {
			printf("! %d\n", mid);
			return 0;
		}
		if (det * rv > 0) {
			r = mid;
			rv = det;
		} else {
			l = mid;
			lv = det;
		}
	}
	printf("! -1\n");
	return 0;
}
