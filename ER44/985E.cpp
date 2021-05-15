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
#include <time.h>
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, k, d;
int a[N];
int sum[N];
bool vis[N];
int main() {
	cin>>n>>k>>d;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(vis, false, sizeof(vis));
	memset(sum, 0, sizeof(sum));
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i) {
		if (a[i] - a[1] <= d && i >= k) {
			vis[i] = true;
			sum[i] = sum[i-1]+1;
			continue;
		}
		if (i < k || a[i] - a[i-k+1] > d) {
			sum[i] = sum[i-1];
			continue;
		}
		int l = 0, r = i-k;
		while(l < r) {
			int mid = (l+r)/2;
			if (a[i] - a[mid+1] <= d) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		if (sum[i-k]-(r > 1 ? sum[r-1] : 0) > 0) {
			vis[i] = true;
			sum[i] = sum[i-1]+1;
		} else {
			sum[i] = sum[i-1];
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cout<<i<<" "<<vis[i]<<" "<<sum[i]<<endl;
	// }
	if (vis[n]) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
