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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int main() {
	cin>>t;
	for (int cas=1;cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= k-3; ++i) {
			printf("%d ", 1);
		}
		n-=(k-3);
		k = 3;
		if (n%2) {
			printf("%d %d %d\n", 1, n/2, n/2);
		} else {
			if ((n/2)%2) {
				printf("%d %d %d\n", 2, n/2-1, n/2-1);
			} else {
				printf("%d %d %d\n", n/2, n/4, n/4);
			}
		}
	}
  return 0;
}
