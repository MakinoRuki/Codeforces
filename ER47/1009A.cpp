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
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int c[N], a[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
	}
	int ans=0;
	int j = 1;
	for (int i = 1; i <= m; ++i) {
		while(j <= n && c[j] > a[i]) {
			j++;
		}
		if (j <= n) {
			ans++;
			j++;
		}
	}
	cout<<ans<<endl;
  return 0;
}
