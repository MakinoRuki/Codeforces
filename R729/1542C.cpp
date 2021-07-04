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
int t, m;
int k;
int q;
int main() {
	vector<vector<ll>> v = {{2,2},{3,3},{4,2},{5,5},{7,7},{8,2},{9,3},{11,11},{13,13},{16,2},{17,17},{19,19},{23,23},{25,5},{27,3},{29,29},{31,31},{32,2},{37,37},{41,41},{43,43},{47,47}};
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll n;
		scanf("%lld", &n);
		ll ans = 0LL;
		int cur = 0;
		while(n) {
			ll det = n-n/v[cur][1];
			ans = (ans + det * v[cur][0] % mod) % mod;
			n = n/v[cur][1];
			cur++;
		}
		printf("%lld\n", ans);
	}
  return 0;
}
