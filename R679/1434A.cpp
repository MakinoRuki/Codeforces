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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[7];
int b[N];
int find(int lb, int i, int ub) {
	int l=1, r=ub;
	while(l<r) {
		int mid=(l+r)/2;
		if (b[mid]-a[i]>=lb) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return r;
}
int main() {
	for (int i = 1; i <= 6; ++i) {
		scanf("%d", &a[i]);
	}
	cin>>n;
	for (int i =1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	sort(a+1, a+7);
	sort(b+1, b+n+1);
	int ans=inf+1;
	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= n; ++j) {
			int mind=b[j]-a[i];
			int maxd=b[j]-a[i];
			int ub=n+1;
			for (int i2=6; i2 >= 1; --i2) {
				int id=find(mind, i2, ub);
				if (id<ub) {
					maxd=max(maxd, b[ub-1]-a[i2]);
				}
				ub=id;
			}
			if (ub<=1) {
				ans=min(ans, maxd-mind);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
