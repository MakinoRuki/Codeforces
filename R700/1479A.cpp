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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
bool check(int id) {
	if ((id -1 < 1 || a[id-1]>a[id]) && (id+1>n || a[id+1] > a[id])) {
		return true;
	}
	return false;
}
int main() {
	cin>>n;
	memset(a, -1, sizeof(a));
	if (n == 1) {
		printf("! %d\n", 1);
	} else {
		printf("? %d\n", 1);
		fflush(stdout);
		scanf("%d", &a[1]);
		printf("? %d\n", 2);
		fflush(stdout);
		scanf("%d", &a[2]);
		if (a[1] < a[2]) {
			printf("! %d\n", 1);
		} else {
			int l = 1, r = n;
			while(l < r) {
				int mid=(l+r+1)/2;
				if (a[mid] < 0) {
					printf("? %d\n", mid);
					fflush(stdout);
					scanf("%d", &a[mid]);
				}
				if (mid-1 >= 1 && a[mid-1] < 0) {
					printf("? %d\n", mid-1);
					fflush(stdout);
					scanf("%d", &a[mid-1]);
				}
				if (mid+1<= n && a[mid+1] < 0) {
					printf("? %d\n", mid+1);
					fflush(stdout);
					scanf("%d", &a[mid+1]);
				}
				if (check(mid)) {
					printf("! %d\n", mid);
					return 0;
				}
				if (a[mid] > a[l]) {
					r = mid-1;
				} else {
					if (mid-1 >=1 && a[mid-1]<a[mid]) {
						r = mid-1;
					} else {
						l = mid;
					}
				}
			}
		}
	}
  return 0;
}
