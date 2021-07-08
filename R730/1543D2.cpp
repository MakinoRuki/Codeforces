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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int calc(int x, int y) {
	int res = 0;
	int pw = 1;
	while(x || y) {
		int b1 = x%k;
		int b2 = y%k;
		b1 = (b1 - b2 + k) % k;
		res += pw * b1;
		x /= k;
		y /= k;
		pw *= k;
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		int res;
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				printf("%d\n", i);
				fflush(stdout);
				scanf("%d", &res);
				if (res == 1) break;
			} else {
				if (i % 2) {
					printf("%d\n", calc(i-1, i));
				} else {
					printf("%d\n", calc(i, i-1));
				}
				fflush(stdout);
				scanf("%d", &res);
				if (res == 1) break;
			}
		}
	}
  return 0;
}
