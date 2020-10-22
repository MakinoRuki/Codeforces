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
#define N 6000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
int a[N];
ll comb[22][22];
ll fac[22];
int main() {
	cin>>n;
	memset(comb, 0, sizeof(comb));
	comb[0][0]=1LL;
	for (int i = 1; i <= n; ++i) {
		comb[i][0]=1;
		for (int j = 1; j <= min(i, n/2); ++j) {
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
		}
	}
	fac[0]=1LL;
	for (int i = 1; i <= n/2; ++i) {
		fac[i]=fac[i-1]*(ll)i;
	}
	//cout<<comb[2][1]
	ll ans=comb[n][n/2]*fac[n/2-1]*fac[n/2-1]/2;
	cout<<ans<<endl;
	return 0;
}
