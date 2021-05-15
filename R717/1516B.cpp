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
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int tot=0;
		for (int i = 1; i < n; ++i) {
			int det = min(k, a[i]);
			tot += det;
			a[i] -= det;
			k -= det;
		}
		a[n] += tot;
		for (int i = 1; i <= n; ++i) {
			printf("%d", a[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
