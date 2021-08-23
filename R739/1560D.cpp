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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int calc(ll a, ll b) {
	vector<int> d1, d2;
	d1.clear();
	d2.clear();
	while(a) {
		d1.push_back(a%10);
		a/=10;
	}
	while(b) {
		d2.push_back(b%10);
		b/=10;
	}
	reverse(d1.begin(), d1.end());
	reverse(d2.begin(), d2.end());
	int len = 0;
	int j = 0;
	for (int i = 0; i < d2.size(); ++i) {
		while(j < d1.size() && d1[j] != d2[i]) {
			j++;
		}
		if (j >= d1.size()) {
			break;
		}
		len++;
		j++;
	}
	return (int)d1.size() + (int)d2.size() - 2*len;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		int ans = 11;
		for (int p = 0; p <= 60; ++p) {
			ans = min(ans, calc((ll)n, (1LL<<p)));
		}
		printf("%d\n", ans);
	}
  return 0;
}
