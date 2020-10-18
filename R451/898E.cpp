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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
bool sq[N];
int main() {
	cin>>n;
	memset(sq, false, sizeof(sq));
	int sqn=0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		int r=(int)sqrt(a[i]);
		if (r*r==a[i]) {
			sq[i]=true;
			sqn++;
		}
	}
	int sqnn=n-sqn;
	if (sqn > n/2) {
		vector<int> vs;
		int det=sqn-n/2;
		int zn=0;
		for (int i = 1; i <= n; ++i) {
			if (sq[i]) {
				vs.push_back(a[i]);
				if (a[i]==0) {
					zn++;
				}
			}
		}
		int nzn=sqn-zn;
		ll ans=0;
		if (nzn>=det) {
			ans=det;
		} else {
			ans=nzn+(det-nzn)*2LL;
		}
		cout<<ans<<endl;
	} else if (sqnn > n/2) {
		int det=sqnn-n/2;
		vector<pair<ll, int>> vs;
		vs.clear();
		for (int i = 1; i <= n; ++i) {
			if (!sq[i]) {
				ll r=(ll)sqrt(a[i]);
				ll x=min(a[i]-r*r, (r+1)*(r+1)-a[i]);
				vs.push_back(make_pair(x, a[i]));
			}
		}
		sort(vs.begin(), vs.end());
		ll ans=0;
		for (int i = 0; i< det; ++i) {
			ans += vs[i].first;
		}
		cout<<ans<<endl;
	} else {
		cout<<0<<endl;
	}
	return 0;
}
