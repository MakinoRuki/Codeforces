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
#define N 300005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
ll a[N];
int bits[N];
int id1[61];
int id2[61];
ll sum[2][61];
ll num[2][61];
int pre[61];
int getbits(ll x) {
	int cnt=0;
	while(x) {
		if (x&1) cnt++;
		x/=2;
	}
	return cnt;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		bits[i] = getbits(a[i]);
	}
	memset(id1, 0, sizeof(id1));
	memset(id2, 0, sizeof(id2));
	memset(pre, 0, sizeof(pre));
	memset(sum, 0, sizeof(sum));
	memset(num, 0, sizeof(num));
	ll ans = 0LL;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 60; ++j) {
			if (j < bits[i]) {
				id1[j] = i;
				id2[j] = i;
				sum[0][j] = 0;
				sum[1][j] = 0;
				num[0][j] = 0;
				num[1][j] = 0;
				pre[j] = 0;
			} else if (j==bits[i]) {
				sum[1][j] += bits[i];
				while(id2[j]+1 < i && sum[0][j]+bits[id2[j]+1] <= sum[1][j]-2*j) {
					id2[j]++;
					sum[0][j] += bits[id2[j]];
					if (sum[0][j]%2==0) num[0][j]++;
					else num[1][j]++;
				}
				// if (sum[0][j] <= sum[1][j]-2*j) {
				// 	if (j>1) cout<<"??"<<i<<" "<<j<<endl;
				// 	ans += id2[j]-id1[j]+1;
				// }
				if (sum[1][j]%2==0) {
					ans += num[0][j];
					if (0 <= sum[1][j]-2*j) {
						ans++;
					}
				} else {
					ans += num[1][j];
				}
				pre[j] = i;
			} else {
				sum[1][j] += bits[i];
				if (pre[j] < 1) {
					continue;
				}
				while(id2[j]+1<pre[j] && sum[0][j]+bits[id2[j]+1] <= sum[1][j]-2*j) {
					id2[j]++;
					sum[0][j] += bits[id2[j]];
					if (sum[0][j]%2==0) num[0][j]++;
					else num[1][j]++;
				}
				// if (sum[0][j] <= sum[1][j]-2*j) {
				// 	if (j>1) cout<<"!!"<<i<<" "<<j<<endl;
				// 	ans += id2[j]-id1[j]+1;
				// }
				if (sum[1][j]%2==0) {
					ans += num[0][j];
					if (0 <= sum[1][j]-2*j) {
						ans++;
					}
				} else {
					ans += num[1][j];
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
