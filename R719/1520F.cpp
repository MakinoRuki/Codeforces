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
int t, n, m;
int k;
int bit[N];
int sum[N];
int lowbit(int x) {
	return x&(-x);
}
void update(int id) {
	while(id <= n) {
		bit[id] += 1;
		id += lowbit(id);
	}
}
int query(int id) {
	int res=0;
	while(id) {
		res += bit[id];
		id -= lowbit(id);
	}
	return res;
}
int main() {
	cin>>n>>t;
	memset(bit, 0, sizeof(bit));
	memset(sum, -1, sizeof(sum));
	while(t-->0) {
		scanf("%d", &k);
		int l = 1, r = n;
		while(l < r) {
			int mid = (l+r)/2;
			int cnt=0;
			if (sum[mid] >= 0) {
				cnt = sum[mid];
				cnt -= query(mid); 
			} else {
				printf("? %d %d\n", 1, mid);
				fflush(stdout);
				scanf("%d", &sum[mid]);
				sum[mid] = mid - sum[mid] + query(mid);
				cnt = sum[mid] - query(mid);
			}
			if (cnt >= k) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		printf("! %d\n", r);
		fflush(stdout);
		update(r);
	}
  return 0;
}
