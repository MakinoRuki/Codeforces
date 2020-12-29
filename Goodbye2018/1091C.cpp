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
int t, n, k;
int main() {
	cin>>n;
	set<ll> ss;
	ss.clear();
	for (ll i = 1; i * i <= n; ++i) {
		if (n%i==0) {
			ll k = n/i;
			ss.insert(k+k*(k-1)/2*i);
			if (n/i != i) {
				ll k = i;
				ss.insert(k+k*(k-1)/2*(n/i));
			}
		}
	}
	vector<ll> vs(ss.begin(), ss.end());
	for (int i = 0; i < vs.size(); ++i) {
		printf("%lld", vs[i]);
		if (i < vs.size()-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
