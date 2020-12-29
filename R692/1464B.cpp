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
#define M 31
#define N 100002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, x, y;
string s;
int a[N];
int main() {
	cin>>s;
	n = s.size();
	cin>>x>>y;
	int zn = 0;
	int on = 0;
	int qn = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i]=='0') {
			a[i] = 0;
			zn++;
		} else if (s[i]=='1') {
			a[i] = 1;
			on++;
		} else {
			a[i] = -1;
			qn++;
		}
	}
	if (x>y) {
		ll ans=0LL;
		int pre=0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < 0) {
				a[i] = 0;
				zn++;
			}
			if (a[i] == 0) {
				ans += (ll)(i-pre)*(ll)y;
				pre++;
			} else {
				ans += (ll)pre * (ll)x;
			}
		}
		pre=0;
		ll cur=ans;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '?') {
				cur = cur-(ll)(i-pre)*(ll)y+(ll)pre*(ll)x;
				ll c1=on-(i-pre);
				ll c0=zn-pre-1;
				cur = cur-c1*(ll)x+c0*(ll)y;
				ans = min(ans, cur);
				zn--;
				on++;
			} else if (s[i]=='0') {
				pre++;
			}
		}
		printf("%lld\n", ans);
	} else {
		ll ans=0LL;
		int pre=0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < 0) {
				a[i] = 1;
				on++;
			}
			if (a[i] == 0) {
				ans += (ll)(i-pre)*(ll)y;
				pre++;
			} else {
				ans += (ll)pre * (ll)x;
			}
		}
	//	cout<<"ans="<<ans<<endl;
		pre=0;
		ll cur=ans;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '?') {
				cur = cur+(ll)(i-pre)*(ll)y-(ll)pre*(ll)x;
				ll c1=on-(i-pre+1);
				ll c0=zn-pre;
				cur = cur+c1*(ll)x-c0*(ll)y;
				ans = min(ans, cur);
				zn++;
				on--;
			} else if (s[i]=='0') {
				pre++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
