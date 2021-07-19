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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q, n, k;
int a[N], t[N];
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			t[i] = -1;
		}
		for (int i = 1; i <= k; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= k; ++i) {
			scanf("%d", &t[a[i]]);
		}
		set<pair<int,int>> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			if (t[i] >= 1) {
				ss.insert(make_pair(t[i]+i-1, i));
			}
		}
		int mv = INT_MAX;
		int cur = 0;
		for (int i = 1; i <= n; ++i) {
			int res = INT_MAX;
			if (mv < INT_MAX) {
				res = min(res, mv + cur);
			}
			if (!ss.empty()) {
				auto top = *ss.begin();
				res = min(res, top.first - (i-1));
			}
			if (t[i] >= 1) {
				if (mv < INT_MAX) {
					mv = min(mv+cur, t[i]);
				} else {
					mv = t[i];
				}
				cur = 0;
				ss.erase(make_pair(t[i]+i-1, i));
			}
			cur++;
			printf("%d", res);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
