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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d",&n,&k);
		vector<ll> ns;
		ns.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			ns.push_back((k-a[i]%k+k)%k);
		}
		sort(ns.begin(), ns.end());
		for (int i = 1; i < ns.size(); ++i) {
			if (ns[i] != 0 && ns[i]%k==ns[i-1]%k) {
				ns[i] = ns[i-1]+k;
			}
		}
		sort(ns.begin(), ns.end());
		ll ans = 0LL;
		ll pre = 0;
		for (int i = 0; i < ns.size(); ++i) {
			if (ns[i]==0) continue;
			ans += ns[i]-pre;
			ans++;
			pre = ns[i]+1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
