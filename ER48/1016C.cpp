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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll a[N], b[N];
ll sa[N], sb[N];
ll sa1[N], sa2[N];
ll sb1[N], sb2[N];
int main() {
	cin>>n;
	memset(sa, 0LL, sizeof(sa));
	memset(sb, 0LL, sizeof(sb));
	memset(sa1, 0LL, sizeof(sa1));
	memset(sa2, 0LL, sizeof(sa2));
	memset(sb1, 0LL, sizeof(sb1));
	memset(sb2, 0LL, sizeof(sb2));
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sa[i] = sa[i-1]+a[i];
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &b[i]);
		sb[i] = sb[i-1]+b[i];
	}
	for (int i = n; i >= 1; --i) {
		sa1[i] = (n-i+1)*a[i] + sa1[i+1];
		sa2[i] = sa2[i+1] + sa[n]-sa[i-1];
	}
	for (int i = n; i >= 1; --i) {
		sb1[i] = (n-i+1)*b[i] + sb1[i+1];
		sb2[i] = sb2[i+1] + sb[n]-sb[i-1];
	}
	ll ans = 0LL;
	int cx=1, cy=1;
	int ct=0;
	ll cur=0LL;
	while(true) {
		if (cx==1) {
			ll tot = sa2[cy+1] + (ll)ct*(sa[n]-sa[cy]);
			tot += sb1[cy] + (ll)(ct+n-cy)*(sb[n]-sb[cy-1]);
			ans = max(ans, tot+cur);
		} else {
			ll tot= sb2[cy+1] + (ll)ct*(sb[n]-sb[cy]);
			tot += sa1[cy] + (ll)(ct+n-cy)*(sa[n]-sa[cy-1]);
			ans = max(ans, tot+cur);
		}
		if (cx==1) {
			cx++;
			ct++;
			cur += (ll)ct*(ll)b[cy];
			cy++;
			if (cy<=n) {
				ct++;
				cur += (ll)ct*(ll)b[cy];
			} else {
				break;
			}
		} else {
			cx--;
			ct++;
			cur += (ll)ct*(ll)a[cy];
			cy++;
			if (cy<=n) {
				ct++;
				cur += (ll)ct*(ll)a[cy];
			} else {
				break;
			}
		}
	}
	cout<<ans<<endl;
  return 0;
}
