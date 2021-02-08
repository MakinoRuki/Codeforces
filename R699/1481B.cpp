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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
int t, n, k;
int h[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &h[i]);
		}
		int cur=1;
		int ans=-1;
		while(true) {
			int i;
			int res=-1;
			for (i = 1; i < n; ++i) {
				if (h[i] >= h[i+1]) {
					continue;
				} else {
					h[i]++;
					res = i;
					break;
				}
			}
			if (cur == k || res < 0) {
				ans = res;
				break;
			} else {
				cur++;
			}
		}
		printf("%d\n", ans);
	}
  return 0;
}
