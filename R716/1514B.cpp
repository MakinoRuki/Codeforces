#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 200
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t, n, k;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		ll res = 1LL;
		for (int i =1 ; i <= k; ++i) {
			res = res * (ll)n % mod;
		}
		printf("%lld\n", res);
	}
	return 0;
}

/*myturn.ca.gov*/
