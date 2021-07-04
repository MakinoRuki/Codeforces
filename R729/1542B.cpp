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
#define N 52
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
ll pw[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n,a,b;
		scanf("%d%d%d", &n, &a, &b);
		if (n == 1) {
			puts("Yes");
			continue;
		}
		if (a == 1) {
			if (b > 1) {
				if (n%b == 1) {
					puts("Yes");
				} else {
					puts("No");
				}
			} else {
				puts("Yes");
			}
			continue;
		}
		ll cur = 1;
		bool ok = false;
		while(cur <= n) {
			if ((n-cur)%b == 0) {
				ok = true;
				break;
			}
			cur *= (ll)a;
		}
		if (ok) puts("Yes");
		else puts("No");
	}
  return 0;
}
