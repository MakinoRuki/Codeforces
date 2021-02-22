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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i =1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int c0=0,c1=0,c2=0;
		for (int i = 1; i <= n; ++i) {
			if (a[i]%3==0) c0++;
			else if (a[i]%3==1) c1++;
			else c2++;
		}
		int cnt = n/3;
		int ans=0;
		if (c0>cnt) {
			if (c1<cnt) {
				int det = min(c0-cnt, cnt-c1);
				c0 -= det;
				c1+=det;
				ans += det;
			}
			if (c2 < cnt) {
				int det = min(c0-cnt, cnt-c2);
				c0 -= det;
				c2+=det;
				ans += 2*det;
			}
		}
		if (c1>cnt) {
			if (c2<cnt) {
				int det = min(c1-cnt, cnt-c2);
				c1 -= det;
				c2+=det;
				ans += det;
			}
			if (c0 < cnt) {
				int det = min(c1-cnt, cnt-c0);
				c1 -= det;
				c0+=det;
				ans += 2*det;
			}
		}
		if (c2>cnt) {
			if (c0<cnt) {
				int det = min(c2-cnt, cnt-c0);
				c2 -= det;
				c0+=det;
				ans += det;
			}
			if (c1 < cnt) {
				int det = min(c2-cnt, cnt-c1);
				c2 -= det;
				c1+=det;
				ans += 2*det;
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}

