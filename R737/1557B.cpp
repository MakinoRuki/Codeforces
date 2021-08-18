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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			rk.push_back(make_pair(a[i], i));
		}
		sort(rk.begin(), rk.end());
		int cnt=0;
		for (int i = 0; i < rk.size(); ++i) {
			if (i == 0 || rk[i].second != rk[i-1].second+1) {
				cnt++;
			}
		}
		if (cnt <= k) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
  return 0;
}
