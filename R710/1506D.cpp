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
#define M 25
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		vector<int> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			rk.push_back(a[i]);
		}
		sort(rk.begin(), rk.end());
		int cnt=0;
		int maxv=0;
		for (int i = 0; i < rk.size(); ++i) {
			if (i==0 || rk[i] == rk[i-1]) {
				cnt++;
			} else {
				maxv=max(maxv, cnt);
				cnt=1;
			}
		}
		maxv=max(maxv, cnt);
		if (maxv > n-maxv) {
			printf("%d\n", maxv-(n-maxv));
		} else {
			if (n%2) puts("1");
			else puts("0");
		}
	}
  return 0;
}
