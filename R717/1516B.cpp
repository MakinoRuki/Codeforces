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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int sum[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sum[0] = 0;
		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i-1] ^ a[i];
		}
		bool ok = false;
		for (int i = 1; i < n; ++i) {
			int res = sum[i];
			int j = i+1;
			int res2 = 0;
			int cnt=0;
			bool f = false;
			while(j <= n) {
				res2 ^= a[j];
				if (res2 == res) {
					cnt++;
					res2 = 0;
					if (j==n) f = true;
				}
				j++;
			}
			if ((f || res2==0) && cnt >= 1) {
				ok=true;
				break;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
