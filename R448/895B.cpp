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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,x,k;
int a[N];
int main() {
	cin>>n>>x>>k;
	unordered_map<int, int> cnt;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	sort(a+1, a+n+1);
	ll ans=0LL;
	int i1=0,i2=0;
	int s1=0,s2=0;
	for (int i = 1; i <= n; ++i) {
		ll r=a[i]%x;
		ll ub=a[i]-r-(ll)(k-1)*(ll)x;
		ll lb=a[i]-r-(ll)k*(ll)x+1;
		if (k==0) {
			if (a[i]%x==0) {
				continue;
			}
			ub=a[i];
			lb=a[i]-r+1;
		}
		while(i1+1<=i && a[i1+1]<=ub) {
			i1++;
		}
		while(i2<=i && a[i2]<lb) {
			i2++;
		}
		if (i2<=i1) {
			ans += i1-i2+1;
			if (i2<=0) ans--;
		}
	}
	for (auto itr : cnt) {
		ll num=itr.second;
		if (num>1) {
			if ((itr.first) % x==0 && k==1) {
				ans += num*(num-1)/2;
			} else if ((itr.first) % x !=0 && k==0) {
				ans += num*(num-1)/2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
