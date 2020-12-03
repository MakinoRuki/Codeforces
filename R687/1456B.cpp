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
int n;
int a[N];
int pw[N];
int getpw(int x) {
	int pw=0;
	if (x==0) return -1;
	for (pw=0; (1LL<<pw)<=x; ++pw) {}
	return pw-1;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		pw[i] = getpw(a[i]);
	}
	for (int i = 1; i + 2 <= n; ++i) {
		if (pw[i]==pw[i+1] && pw[i]==pw[i+2]) {
			cout<<1<<endl;
			return 0;
		}
	}
	int ans=inf;
	for (int i = 1; i < n; ++i) {
		int lv=0;
		for (int l = i; l >= 1; --l) {
			lv ^= a[l];
			int rv=0;
			for (int r = i+1; r <= n; ++r) {
				rv ^= a[r];
				if (lv > rv) {
					ans = min(ans, r-l-1);
					break;
				}
			}
		}
	}
	if (ans >= inf) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
