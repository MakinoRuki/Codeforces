#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
int n;
int a[N];
int main() {
	cin>>n;
	int tot=0;
	vector<int> idx;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		tot+=a[i];
		if (a[i]) {
			idx.push_back(i);
		}
	}
	ll ans=1LL<<62;
	for (int i = 2; i <= tot; ++i) {
		if (tot % i) continue;
		ll cur=0;
		for (int j = 0; j < idx.size(); ++j) {
			int k = j/i;
			cur += (ll)abs(idx[k*i+i/2] - idx[j]);
		}
		ans = min(ans, cur);
	}
	if (ans < 1LL<<62) cout<<ans<<endl;
	else cout<<"-1"<<endl;
	return 0;
}
