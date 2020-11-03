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
#define M 2002
#define N 200002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,k;
int a[N];
int b[N];
int p[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			p[a[i]]=i;
		}
		for (int i = 1; i <= k; ++i) {
			scanf("%d", &b[i]);
		}
		ll res=1LL;
		unordered_set<int> ss;
		ss.clear();
		for (int i = k; i >= 1; --i) {
			int pos=p[b[i]];
			int cnt=2;
			if (pos-1<1 || ss.find(a[pos-1])!=ss.end()) {
				cnt--;
			}
			if (pos+1>n || ss.find(a[pos+1]) != ss.end()) {
				cnt--;
			}
			res = res*(ll)cnt % mod2;
			ss.insert(b[i]);
		}
		printf("%lld\n", res);
	}
	return 0;
}
