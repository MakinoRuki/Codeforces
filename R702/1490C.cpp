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
ll x;
unordered_map<ll, int> mp;
int main() {
	cin>>t;
	mp.clear();
	for (ll i = 1; i <= 10000; ++i) {
		ll cb = i*i*i;
		mp[cb] = i;
	}
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld", &x);
		bool found=false;
		for (ll i = 1; i <= 10000; ++i) {
			if (i*i*i < x) {
				ll det = x-i*i*i;
				if (mp.find(det) != mp.end()) {
					found=true;
					break;
				}
			}
		}
		if (found) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
  return 0;
}

