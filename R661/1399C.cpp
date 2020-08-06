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
#define N 100
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int w[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &w[i]);
		}
		sort(w+1, w+n+1);
		int ans=0;
		for (int tw = 1; tw <= 2*n; ++tw) {
			int l = 1, r = n;
			int cnt=0;
			while(l < r) {
				if (w[l]+w[r] > tw) {
					r--;
				} else if (w[l] + w[r] < tw) {
					l++;
				} else {
					cnt++;
					l++;
					r--;
				}
			}
			ans = max(ans, cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}
