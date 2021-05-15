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
#define N 1005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, m, c;
int a[N];
int main() {
	cin>>n>>m>>c;
	int l = 1;
	int r = n;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= m; ++i) {
		int p;
		scanf("%d", &p);
		if (p <= (c+1)/2) {
			int x = l;
			while(x > 1 && a[x-1] > p) {
				x--;
			}
			printf("%d\n", x);
			fflush(stdout);
			a[x] = p;
			if (x == l) l++;
		} else {
			int x = r;
			while(x < n && a[x+1] < p) {
				x++;
			}
			printf("%d\n", x);
			fflush(stdout);
			a[x] = p;
			if (x == r) r--;
		}
		int j;
		for (j = 1; j <= n; ++j) {
			if (a[j] == 0) break;
		}
		if (j > n) {
			// printf("i=%d\n", i);
			// for (int i = 1; i <= n; ++i) {
			// 	printf("%d ", a[i]);
			// }
			// cout<<endl;
			return 0;
		}
	}
	// printf("i=%d\n", m+1);
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%d ", a[i]);
	// }
	// cout<<endl;
	return 0;
}

/*myturn.ca.gov*/
