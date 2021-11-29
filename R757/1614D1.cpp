#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 5000005
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
int s;
int t;
int n, m, k;
int a[N];
int cnt[M];
ll dp[M];
int num[M];
int main() {
	memset(cnt, 0, sizeof(cnt));
	memset(num, 0, sizeof(num));
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		num[a[i]]++;
	}
	for (int i = 1; i <= n; ++i) {
		for (ll x = 1; x * x <= a[i]; ++x) {
			if (a[i] % x == 0) {
				cnt[x]++;
				if (a[i] /x != x) {
					cnt[a[i]/x]++;
				}
			}
		}
	}
	memset(dp, 0LL, sizeof(dp));
	int g;
	for (g = 1; g < M; ++g) {
		if (cnt[g] == n) {
			break;
		}
	}
	for (int i = g; i < M; ++i) {
		for (int j = 2*i; j < M; j += i) {
			if (cnt[j] < cnt[i]) {
				dp[j] = max(dp[j], dp[i] + (ll)i * (ll)(cnt[i]-cnt[j]));
			}
		}
	}
	ll ans= 0LL;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dp[a[i]] + (ll)num[a[i]] * (ll)a[i]);
	}
	cout<<ans<<endl;
  return 0;
}

