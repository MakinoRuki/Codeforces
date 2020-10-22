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
#define N 100002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m,k;
int a,b,c;
int x,y;
unordered_map<int, int> dp;
ll getpw(int a1, int b1) {
	ll res=1LL;
	while(b1) {
		if (b1&1) res=res*(ll)a1%mod;
		a1=(ll)a1*(ll)a1%mod;
		b1/=2;
	}
	return res;
}
ll dfs(ll z) {
	if (dp.find(z) != dp.end()) {
		return dp[z];
	}
	if (z==1) return 0;
	ll cur=(getpw(2, z-1)-1+mod)%mod;
	//cout<<z<<" "<<cur<<endl;
	for (int i=2;(ll)i*(ll)i<=z; ++i) {
		if (z%i==0) {
			cur=(cur-dfs(z/i)+mod)%mod;
			if (z/i!=i) {
				cur=(cur-dfs(i)+mod)%mod;
			}
		}
	}
	return dp[z]=cur;
}
int main() {
	dp.clear();
	cin>>x>>y;
	if (y%x!=0) {
		cout<<0<<endl;
	} else {
		if (y==x) {
			cout<<1<<endl;
		} else {
			dfs(y/x);
			cout<<dp[y/x]<<endl;
		}
	}
	return 0;
}
