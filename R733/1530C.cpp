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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, l, r;
int h, w;
vector<int> a;
vector<int> b;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		a.clear();
		b.clear();
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			a.push_back(x);
		}
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			b.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (int i = 1; i < n; ++i) {
			a[i] += a[i-1];
			b[i] += b[i-1];
		}
		int l = 0, r = 2*n;
		while(l < r) {
			int mid = (l+r)/2;
			int n1 = (n+mid)-(n+mid)/4;
			ll s1 = 0LL, s2 = 0LL;
			if (n1 <= mid) {
				s1 = n1 * 100LL;
			} else {
				int det = n1 - mid;
				s1 = mid * 100LL + a[det-1];
			}
			if (n1 <= n) {
				s2 = b[n1-1];
			} else {
				s2 = b[n-1];
			}
			if (s1 >= s2) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		printf("%d\n", r);
	}
  return 0;
}
