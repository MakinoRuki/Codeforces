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
#define N 300005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll m,d,w;
ll getgcd(ll a, ll b) {
	return b == 0 ? a : getgcd(b, a%b);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld%lld", &m, &d, &w);
		ll g = getgcd(w, d-1);
		w /= g;
		ll b = min(m, d);
		ll x = (b-1)/w;
		ll i = b-x*w;
		ll ans = i * x;
		ll q = (b-1-i+1)/w;
		ll r = (b-1-i+1)%w;
		if (q >= x-1) {
			ans += x*(x-1)/2*w;
		} else {
			ans += q*(q+1)/2*w+(x-1-q)*r;
		}
		printf("%lld\n", ans);
	}
  return 0;
}
