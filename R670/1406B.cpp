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
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
ll a[N];
ll lmx[N],lmi[N];
ll rmx[N],rmi[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i<=n; ++i) {
			scanf("%lld", &a[i]);
		}
		ll pmx=a[1];
		ll pmi=a[1];
		for (int i = 2; i <= n; ++i) {
			lmx[i]=max(pmx*a[i], pmi*a[i]);
			lmi[i]=min(pmx*a[i], pmi*a[i]);
			if (i>2) {
				lmx[i] = max(lmx[i], lmx[i-1]);
				lmi[i] = min(lmi[i], lmi[i-1]);
			}
			pmx=max(pmx, a[i]);
			pmi=min(pmi, a[i]);
		}
		pmx=a[n];
		pmi=a[n];
		for (int i = n-1; i >= 1; --i) {
			rmx[i]=max(pmx*a[i], pmi*a[i]);
			rmi[i]=min(pmx*a[i], pmi*a[i]);
			if (i<n-1) {
				rmx[i] = max(rmx[i], rmx[i+1]);
				rmi[i] = min(rmi[i], rmi[i+1]);
			}
			pmx=max(pmx, a[i]);
			pmi=min(pmi, a[i]);
		}
	//	cout<<rmx[4]<<" "<<rmi[4]<<endl;
		ll res=-(1LL<<61);
		for (int i = 3; i <= n-2; ++i) {
			ll tmp=lmx[i-1]*a[i]*rmx[i+1];
			tmp=max(tmp,lmi[i-1]*a[i]*rmx[i+1]);
			tmp=max(tmp, lmx[i-1]*a[i]*rmi[i+1]);
			tmp=max(tmp, lmi[i-1]*a[i]*rmi[i+1]);
			res=max(res, tmp);
		}
		printf("%lld\n", res);
	}
	return 0;
}
