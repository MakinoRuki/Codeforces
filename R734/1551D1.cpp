#pragma GCC optimize(2)
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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<string> ss;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &n, &m, &k);
		if (n%2) {
			int det = m/2;
			if (k < det) {
				puts("NO");
			} else {
				k -= det;
				if (k % 2) {
					puts("NO");
				} else {
					puts("YES");
				}
			}
		} else {
			if (k%2) {
				puts("NO");
			} else {
				if (m%2==0) puts("YES");
				else {
					int lmt = n*(m-1)/2;
					if (k > lmt) puts("NO");
					else puts("YES");
				}
			}
		}
	}
  return 0;
}
