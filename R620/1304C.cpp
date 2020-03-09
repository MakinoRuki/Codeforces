#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define N 105
using namespace std;
typedef long long ll;
int q, n, m;
ll t[N], l[N], h[N];
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		cin>>n>>m;
		for (int i = 0; i < n; ++i) {
			cin>>t[i]>>l[i]>>h[i];
		}
		ll ct = 0;
		ll pl = m;
		ll pr = m;
		int i = 0;
		for (i = 0; i < n; ++i) {
			if (pl > pr) break;
			ll cl = pl - ((ll)t[i]-(ll)ct);
			ll cr = pr + ((ll)t[i] - (ll)ct);
			pl = max(cl, (ll)l[i]);
			pr = min(cr, (ll)h[i]);
			ct = t[i];
		}
		if (i >= n && pl <= pr) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
