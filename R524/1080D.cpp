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
#define N 500005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll n, k;
		scanf("%lld%lld", &n, &k);
		int pw = 1;
		int sd = n;
		ll pre = 1LL;
		ll k1=k,k2=k;
		while(k2) {
			if (sd==0) break;
			sd--;
			if (2LL*n-sd+1>=62) {
				k2 =0;
				break;
			}
			ll cur = (1LL<<pw)-1;
			if (k1<cur) {
				break;
			}
			k1-=cur;
			if (n-pw>=0) {
				ll x = n-pw;
				cur += pre * (((1LL<<(2*x))-1)/3);
			}
			k2 -= min(cur, k2);
			pw++;
			pre += (1LL<<pw);
		}
		if (k2) cout<<"NO"<<endl;
		else {
			cout<<"YES ";
			printf("%d\n", sd);
		}
	}
	return 0;
}
