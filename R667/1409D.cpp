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
ll n, s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld",&n,&s);
		if (n==1000000000000000000LL) {
			cout<<0<<endl;
		} else {
			ll ans=1000000000000000000LL-n;
			vector<int> ds;
			ds.clear();
			ll m = n;
			while(m) {
				ds.push_back(m%10);
				m/=10;
			}
			reverse(ds.begin(), ds.end());
			int sum=0;
			ll pre=0LL;
			int sz=ds.size();
			ll pw =1LL;
			for (int i = 1; i <= sz; ++i) {
				pw*=10LL;
			}
			ans=min(ans, pw-n);
			for (int i = 0; i < ds.size(); ++i) {
				pw/=10LL;
				if (ds[i]+1<=9) {
					if (sum+ds[i]+1<=s) {
						ans=min(ans, pre+pw*(ds[i]+1)-n);
					}
				}
				sum += ds[i];
				pre += pw*ds[i];
			}
			if (sum<=s) {
				ans=min(ans, 0LL);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
