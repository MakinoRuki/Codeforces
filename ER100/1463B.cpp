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
#define M 20005
#define N 105
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int r, n;
int t;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		ll tot=0LL;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			tot += a[i];
		}
		ll tot1=0LL;
		ll tot2=0LL;
		for (int i = 1; i <= n; ++i) {
			if (i%2) {
				tot1 += abs(a[i]-1);
			} else {
				tot2 += abs(a[i]-1);
			}
		}
		if (tot1*2<=tot) {
			for (int i = 1; i <= n; i += 2) {
				a[i] = 1;
			}
		} else {
			for (int i = 2; i <= n; i += 2) {
				a[i] = 1;
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", a[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
