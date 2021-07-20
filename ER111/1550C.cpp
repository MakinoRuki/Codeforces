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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
string s;
int a[N];
bool check(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i+1; j < v.size(); ++j) {
			if (i == j) continue;
			for (int k = j+1; k < v.size(); ++k) {
				if (k == i || k == j) continue;
				if (v[k] >= v[j] && v[j] >= v[i]) {
					return false;
				}
				if (v[k] <= v[j] && v[j] <= v[i]) {
					return false;
				}
			}
		}
	}
	return true;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		ll ans = n + n-1;
		for (int i = 1; i + 2 <= n; ++i) {
			vector<int> v = {a[i], a[i+1], a[i+2]};
			if (check(v)) {
				ans++;
			}
		}
		for (int i = 1; i + 3 <= n; ++i) {
			vector<int> v = {a[i], a[i+1], a[i+2], a[i+3]};
			if (check(v)) {
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
