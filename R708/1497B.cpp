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
int t, n, m;
int a[N];
int cnt[N];
int main() {
	cin>>t;
	for (int cas=1;cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= m; ++i) {
			cnt[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			cnt[a[i]%m]++;
		}
		int ans=0;
		for (int i = 0; i < m; ++i) {
			if (cnt[i] > 0) {
				int j = (i==0 ? 0 : m-i);
				if (i == j) {
					ans++;
					cnt[i] = 0;
				} else {
					ans++;
					if (cnt[i]>=cnt[j]) {
						int det=max(0, cnt[i]-(cnt[j]+1));
						ans += det;
					} else {
						int det=max(0, cnt[j]-(cnt[i]+1));
						ans += det;
					}
					cnt[i]=0;
					cnt[j]=0;
				}
			}
		}
		printf("%d\n", ans);
	}
  return 0;
}
