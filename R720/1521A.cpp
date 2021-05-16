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
#define N 2002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll a, b;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld", &a, &b);
		if (b==1) {
			puts("NO");
		} else {
			puts("YES");
			if (b == 2) {
				printf("%lld %lld %lld\n", a, 3LL*a, 4LL*a);	
			} else {
				printf("%lld %lld %lld\n", a, (b-1)*a, b*a);
			}
		}
	}
  return 0;
}
