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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll z;
ll x[N];
bool vis[N];
int main() {
	cin>>n>>z;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &x[i]);
	}
	sort(x+1, x+n+1);
	int ans=0;
	int mid=n/2;
	if (n%2) {
		mid=(n+1)/2;
	}
	int j = mid+1;
	for (int i = 1; i <= mid; ++i) {
		while(j <= n && x[j]-x[i]<z) {
			j++;
		}
		if (j<=n) {
			ans++;
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
