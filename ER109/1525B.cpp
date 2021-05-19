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
#define M 52
#define N 100
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int i;
		for (i = 2; i <= n; ++i) {
			if (a[i] < a[i-1]) {
				break;
			}
		}
		if (i > n) {
			puts("0");
		} else {
			if (a[1] == 1 || a[n] == n) {
				puts("1");
			} else if (a[1] == n && a[n] == 1) {
				puts("3");
			} else {
				puts("2");
			}
		}
	}
  return 0;
}
