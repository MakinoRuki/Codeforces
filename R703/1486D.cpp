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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int sum[N];
int main() {
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int l = 1, r = n;
	while(l < r) {
		int mid=(l+r+1)/2;
		for (int i = 0; i <= n; ++i) {
			sum[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i-1];
			if (a[i] < mid) {
				sum[i] += 1;
			}
		}
		int maxv = INT_MIN;
		bool found = false;
		for (int i = 1; i <= n; ++i) {
			if (i-k>=0) {
				maxv=max(maxv, 2*sum[i-k]-(i-k));
			}
			if (maxv > 2*sum[i]-i) {
				found=true;
				break;
			}
		}
		if (found) {
			l = mid;
		} else {
			r = mid-1;
		}
	}
	printf("%d\n", r);
  return 0;
}
