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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N], b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
		}
		vector<pair<int,int>> v1, v2;
		v1.clear();
		v2.clear();
		int tot1=0, tot2=0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > b[i]) {
				v1.push_back(make_pair(a[i]-b[i], i));
				tot1 += a[i]-b[i];
			} else if (a[i] < b[i]) {
				v2.push_back(make_pair(b[i]-a[i], i));
				tot2 += b[i]-a[i];
			}
		}
		if (tot1 != tot2) {
			puts("-1");
		} else {
			vector<pair<int,int>> ans;
			ans.clear();
			int j1 = 0, j2 = 0;
			for (int i = 1; i <= tot1; ++i) {
				ans.push_back(make_pair(v1[j1].second, v2[j2].second));
				v1[j1].first--;
				v2[j2].first--;
				if (v1[j1].first == 0) j1++;
				if (v2[j2].first == 0) j2++;
			}
			printf("%d\n", (int)ans.size());
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
	}
  return 0;
}
