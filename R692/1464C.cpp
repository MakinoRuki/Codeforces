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
int n;
ll t;
string s;
int cnt[27];
int main() {
	cin>>n>>t;
	cin>>s;
	memset(cnt, 0, sizeof(cnt));
	ll sum=0LL;
	for (int i = 1; i <= n; ++i) {
		int c=s[i-1]-'a';
		if (i <= n-2) {
			cnt[c+1]++;
		}
		if (i <= n-1) {
			sum -= (1LL<<c);
		} else {
			sum += (1LL<<c);
		}
	}
	if (t < sum) {
		cout<<"No"<<endl;
	} else {
		ll det=t-sum;
		for (int i = 26; i >= 1; --i) {
			ll q=det/(1LL<<i);
			det -= min(q, (ll)cnt[i]) * (1LL<<i);
		}
		if (det==0) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}
	return 0;
}
