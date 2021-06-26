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
#define N 50
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
int a,b;
ll dp[N][2];
int l, r;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &l, &r);
		vector<int> ds;
		ds.clear();
		int x = l;
		while(x) {
			ds.push_back(x%10);
			x/=10;
		}
		while(ds.size() <= 10) {
			ds.push_back(0);
		}
		for (int i = 0; i <= 10; ++i) {
			ll pre=0LL;
			for (int j = 0; j < i; ++j) {
				pre += dp[j][0] * 9LL;
			}
			dp[i][0] = pre + (i+1);
			int j = i;
			for (j = i-1; j >= 0; --j) {
				if (ds[j] < 9) {
					break;
				}
			}
			if (j < 0) {
				dp[i][1] = (i+1);
			} else {
				pre = dp[j][1];
				int det = (9-ds[j]-1);
				pre += dp[j][0] * (ll)det;
				for (int j2 = j-1; j2 >= 0; --j2) {
					pre += dp[j2][0]*9LL;
				}
				dp[i][1] = pre + (i+1);
			}
		}
		vector<int> ds2;
		ds2.clear();
		x = r;
		while(x) {
			ds2.push_back(x%10);
			x/=10;
		}
		while(ds2.size()<=10) {
			ds2.push_back(0);
		}
		ll tot=0LL;
		int i;
		for (i = ds.size()-1; i >= 0; --i) {
			if (ds[i] < ds2[i]) {
				break;
			}
		}
		tot = dp[i][1];
		int det = ds2[i]-ds[i]-1;
		tot += dp[i][0] * (ll)det;
		for (int j = i-1; j >= 0; --j) {
			tot += dp[j][0] * (ll)ds2[j];
		}
		printf("%lld\n", tot);
	}
  return 0;
}
