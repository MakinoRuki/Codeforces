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
#define N 100
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		int sum=0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum == n) {
			puts("0");
		} else if (sum < n) {
			puts("1");
		} else {
			printf("%d\n", sum-n);
		}
	}
  return 0;
}
