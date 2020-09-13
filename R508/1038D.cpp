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
int n;
ll a[N];
int main() {
	ll tot=0;
	cin>>n;
	int zn=0,pn=0,nn=0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if (a[i]==0) {
			zn++;
		} else if (a[i]>0) {
			pn++;
		} else {
			nn++;
		}
		tot += abs(a[i]);
	}
	if (zn>0) {
		cout<<tot<<endl;
	} else {
		if (pn && nn) {
			cout<<tot<<endl;
		} else if (pn && !nn) {
			if (n==1) {
				cout<<tot<<endl;
				return 0;
			}
			ll minv=a[1];
			for (int i = 2;  i<= n; ++i) {
				minv=min(minv,a[i]);
			}
			cout<<tot-2LL*minv<<endl;
		} else {
			if (n==1) {
				cout<<-tot<<endl;
				return 0;
			}
			ll minv=abs(a[1]);
			for (int i = 2; i <= n; ++i) {
				minv=min(minv, abs(a[i]));
			}
			cout<<tot-2LL*minv<<endl;
		}
	}
	return 0;
}
