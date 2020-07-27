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
#define N 100005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
ll x;
ll a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>x;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		sort(a+1, a+n+1);
		ll sum=0LL;
		int ans=0;
		for (int i = n; i >= 1; --i) {
			sum += a[i];
			if (sum / (n-i+1) >= x) {
				ans = max(ans, n-i+1);
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}
