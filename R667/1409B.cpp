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
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
ll a,b,x,y,n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld%lld%lld%lld", &a,&b,&x,&y,&n);
		// ll res1=max(n-b+y, 0LL);
		// ll res2=min(n, a-x);
		// res1 = -res1*res1+(a-b+n)*res1+a*b-a*n;
		// res2 = -res2*res2+(a-b+n)*res2+a*b-a*n;
		// printf("%lld\n", min(res1, res2));
		ll det1=min(n, a-x);
		ll det2=min(b-y, n-det1);
		ll res1=(a-det1)*(b-det2);
		det1=min(n,b-y);
		det2=min(a-x, n-det1);
		ll res2=(a-det2)*(b-det1);
		printf("%lld\n", min(res1, res2));
	}
	return 0;
}
