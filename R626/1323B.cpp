#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define N 40005
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int n, m, k;
int a[N], b[N];
ll cnt1[N], cnt2[N];
int main() {
	cin>>n>>m>>k;
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin>>b[i];
	}
	int i = 1;
	int cnt=0;
	while(i <= n) {
		if (a[i] == 1) {
			cnt++;
			i++;
		} else {
			if (cnt) {
				for (int j = 1; j <= cnt; ++j) {
					cnt1[j] += cnt-(j-1);
				}
				cnt=0;
			}
			i++;
		}
	}
	if (cnt) {
		for (int j =1 ; j <= cnt; ++j) {
			cnt1[j] += cnt-(j-1);
		}
	}
	i = 1;
	cnt=0;
	while(i <= m) {
		if (b[i] == 1) {
			cnt++;
			i++;
		} else {
			if (cnt) {
				for (int j = 1; j <= cnt; ++j) {
					cnt2[j] += cnt-(j-1);
				}
				cnt=0;
			}
			i++;
		}
	}
	if (cnt) {
		for (int j=1; j <= cnt; ++j) {
			cnt2[j] += cnt-(j-1);
		}
	}
	ll ans=0LL;
	for (int i = 1; i * i <= k; ++i) {
		if (k % i == 0) {
			if (i <= n && k/i <= m) {
				ans += cnt1[i] * cnt2[k/i];
			}
			if (i != k/i && k/i <= n && i <= m) {
				ans += cnt1[k/i] * cnt2[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
