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
#include <queue>
#define N 100005
using namespace std;
typedef long long ll;
int t;
vector<int> nr;
vector<int> ng;
vector<int> nb;
ll getans(vector<int>& a, vector<int>& b, vector<int>& c) {
	int i = 0, j = 0, k = 0;
	ll sum = (1LL<<62);
	for (; j < b.size(); ++j) {
		if (b[j] < a[i]) continue;
		while(i < a.size() && a[i] <= b[j]) i++;
		i--;
		while(k < c.size() && c[k] < b[j]) k++;
		if (k >= c.size()) break;
		ll x = a[i];
		ll y = b[j];
		ll z = c[k];
		ll res = (y-x)*(y-x)+(z-x)*(z-x)+(z-y)*(z-y);
		sum = min(sum, res);
	}
	return sum;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int r,g,b;
		scanf("%d%d%d", &r,&g,&b);
		nr.clear();
		ng.clear();
		nb.clear();
		for (int i = 1; i <= r; ++i) {
			int x;
			scanf("%d", &x);
			nr.push_back(x);
		}
		for (int i = 1; i <= g; ++i) {
			int x;
			scanf("%d", &x);
			ng.push_back(x);
		}
		for (int i = 1; i <= b; ++i) {
			int x;
			scanf("%d", &x);
			nb.push_back(x);
		}
		sort(nr.begin(), nr.end());
		sort(ng.begin(), ng.end());
		sort(nb.begin(), nb.end());
		ll ans = getans(nr, ng, nb);
		//cout<<ans<<endl;
		ans = min(ans, getans(nr, nb, ng));
		//cout<<ans<<endl;
		ans = min(ans, getans(ng, nr, nb));
		//cout<<ans<<endl;
		ans = min(ans, getans(ng, nb, nr));
	//	cout<<ans<<endl;
		ans = min(ans, getans(nb, nr, ng));
		ans = min(ans, getans(nb, ng, nr));
		printf("%lld\n", ans);
	}
	return 0;
}
