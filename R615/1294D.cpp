#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 400005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q, x;
int pw[N];
int main() {
	cin>>q>>x;
	ll ans=0;
	set<ll> has;
	has.clear();
	memset(pw, 0, sizeof(pw));
	for (int i = 1; i <= q; ++i) {
		int y;
		cin>>y;
		int r = y % x;
		has.insert((ll)x * (ll)pw[r] + (ll)r);
		pw[r]++;
		while(has.find(ans) != has.end()) {
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
