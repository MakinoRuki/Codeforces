#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n;
int m[N];
int m2[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &m[i]);
	}
	for (int i = n; i >= 1; --i) {
		if (i == n) {
			m2[i] = m[i]-i+1;
		} else {
			m2[i] = max(m2[i+1], m[i]-i+1);
		}
	}
	ll sum=0;
	ll ans=0;
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			sum++;
		} else {
			if (sum <= m[i]) {
				sum++;
			} else {
				if (i < n && sum-i<m2[i+1]) {
					sum++;
				}
				ans += (ll)sum-(ll)m[i]-1LL;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
