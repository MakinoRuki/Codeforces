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
#include <queue>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,m;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		ll i=(ll)sqrt(n);
		if (i*i<n) {
			i++;
		}
		ll det=i-1+(n+i-1)/i-1;
		printf("%lld\n", det);
	}
	return 0;
}
