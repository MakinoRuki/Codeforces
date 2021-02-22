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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld", &n);
		ll ub = (ll)sqrt(2*n-1);
	//	cout<<ub<<endl;
		ll res =0LL;
		if (ub >= 3) {
			res = (ub-3)/2+1;
		}
		printf("%lld\n", res);
	}
  return 0;
}
