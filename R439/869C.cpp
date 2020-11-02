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
#define M 20005
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int a,b,c;
ll comb[N][N];
ll fac[N];
ll getres(int x, int y) {
	int z=min(x,y);
	ll res=1LL;
	for (int i = 1; i <= z; ++i) {
		ll tmp=comb[x][i] * comb[y][i] % mod2 * fac[i] % mod2;
		res=(res+tmp)%mod2;
	}
	return res;
}
int main() {
	cin>>a>>b>>c;
	int n = max(max(a,b),c);
	comb[0][0]=1LL;
	for (int i = 1; i <= n; ++i) {
		comb[i][0]=1LL;
		for (int j =1; j <= i; ++j) {
			comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod2;
		}
	}
	fac[0]=1LL;
	for (int i = 1; i <= n; ++i) {
		fac[i]=fac[i-1]*(ll)i%mod2;
	}
	ll ans=1LL;
	ans = ans * getres(a,b)%mod2;
	ans = ans*getres(b,c)%mod2;
	ans=ans*getres(a,c)%mod2;
	cout<<ans<<endl;
	return 0;
}
