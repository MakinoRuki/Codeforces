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
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q;
string s,t;
int cnt[N];
int main() {
	cin>>n>>m>>q;
	cin>>s>>t;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i+m-1 <= n; ++i) {
		int j;
		for (j = 1; j <= m; ++j) {
			if (s[i+j-1-1] != t[j-1]) {
				break;
			}
		}
		if (j > m) {
			cnt[i+m-1]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cnt[i] += cnt[i-1];
	}
	while(q-->0) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (l+m-1<=r) {
			printf("%d\n", cnt[r]-cnt[l+m-2]);
		} else {
			printf("%d\n", 0);
		}
	}
  return 0;
}
