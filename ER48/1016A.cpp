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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
int n, m;
ll a[N];
int main() {
	cin>>n>>m;
	ll pre = 0LL;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		ll cnt = (pre+a[i])/m;
		printf("%lld", cnt);
		if (i < n) cout<<" ";
		else cout<<endl;
		pre = (pre+a[i])%m;
	}
  return 0;
}
