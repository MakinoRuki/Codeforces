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
#define N 100005
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
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	bool ok = false;
	for (int i = 1; i + 2 <= n; ++i) {
		if (a[i] + a[i+1] > a[i+2]) {
			ok=true;
			break;
		}
	}
	if (ok) puts("YES");
	else puts("NO");
  return 0;
}
