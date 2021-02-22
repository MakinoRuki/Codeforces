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
#define M 21
#define N 20005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
map<pair<int,int>, int> res;
int main() {
	scanf("%d", &n);
	res.clear();
	int l = 1, r = n;
	while(l < r) {
		int id;
		int mid = (l + r) / 2;
		if (res.find(make_pair(l,r)) != res.end()) {
			id = res[make_pair(l,r)];
		} else {
			printf("? %d %d\n", l, r);
			fflush(stdout);
			scanf("%d", &id);
			res[make_pair(l,r)] = id;
		}
		if (id <= mid) {
			if (l == mid) {
				l = mid+1;
				continue;
			}
			int id2;
			if (res.find(make_pair(l,mid)) == res.end()) {
				printf("? %d %d\n", l, mid);
				fflush(stdout);
				scanf("%d", &id2);
				res[make_pair(l,mid)] = id2;
			} else {
				id2 = res[make_pair(l,mid)];
			}
			if (id2 == id) {
				r = mid;
			} else {
				l = mid+1;
			}
		} else {
			int id2;
			if (mid + 1== r) {
				r = mid;
				continue;
			}
			if (res.find(make_pair(mid+1,r)) == res.end()) {
				printf("? %d %d\n", mid+1, r);
				fflush(stdout);
				scanf("%d", &id2);
				res[make_pair(mid+1,r)] = id2;
			} else {
				id2 = res[make_pair(mid+1,r)];
			}
			if (id2 == id) {
				l = mid+1;
			} else {
				r = mid;
			}
		}
	}
	printf("! %d\n", r);
  return 0;
}
