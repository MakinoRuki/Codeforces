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
int r, n;
int t;
int b[2*N];
int rv[2*N], lv[2*N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
		}
		sort(b+1, b+n+1);
		for (int i = n; i >= 1; --i) {
			rv[i] = 2*n-b[i]-(n-i);
		}
		for (int i = 1; i <= n; ++i) {
			lv[i] = b[i]-1-(i-1);
		}
		int ub, lb;
		for (int i = 1; i <= n; ++i) {
			if (i==1) {
				ub=rv[i];
			} else {
				ub = min(ub, rv[i]+i-1);
			}
		}
		for (int i = n; i >= 1; --i) {
			if (i==n) {
				lb = n-lv[i];
			} else {
				lb = max(lb, i-lv[i]);
			}
		}
		if (lb <= ub) {
			printf("%d\n", ub-lb+1);
		} else {
			cout<<0<<endl;
		}
	}
	return 0;
}
