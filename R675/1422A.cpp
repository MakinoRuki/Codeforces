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
#define N 10002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll a,b,c,d;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld%lld",&a,&b,&c);
		d = a+b+c-1;
		printf("%lld\n", d);
	}
	return 0;
}
