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
#define eps 1e-7
#define M 20005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll a,b;
ll x,y,z;
int main() {
	cin>>a>>b>>x>>y>>z;
	a -= y;
	b -= y;
	a -= x*2;
	b -= 3*z;
	ll res=0LL;
	if (a<0) res+=abs(a);
	if (b<0) res+=abs(b);
	cout<<res<<endl;
	return 0;
}
