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
int main() {
	scanf("%d", &n);
	printf("? %d %d\n", 1, n);
	fflush(stdout);
	int idx;
	scanf("%d", &idx);
	int lr = 0;
	if (idx == 1) {
		lr = 1;
	} else if (idx == n) {
		lr = 0;
	} else {
		int id2;
		printf("? %d %d\n", idx, n);
		fflush(stdout);
		scanf("%d", &id2);
		if (id2 == idx) {
			lr = 1;
		} else {
			lr = 0;
		}
	}
	if (lr) {
		int l = idx+1, r = n;
		while(l < r) {
			int mid = (l+r)/2;
			printf("? %d %d\n", idx, mid);
			fflush(stdout);
			int id2;
			scanf("%d", &id2);
			if (id2 == idx) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		printf("! %d\n", r);
	} else {
		int l = 1, r = idx-1;
		while(l < r) {
			int mid = (l+r+1)/2;
			printf("? %d %d\n", mid, idx);
			fflush(stdout);
			int id2;
			scanf("%d", &id2);
			if (id2 == idx) {
				l = mid;
			} else {
				r = mid-1;
			}
		}
		printf("! %d\n", r);
	}
  return 0;
}
