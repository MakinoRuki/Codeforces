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
#define N 150
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,k;
vector<pair<int,int>> ss;
int main() {
	cin>>n>>k;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		int t,b;
		scanf("%d%d",&t,&b);
		ss.push_back(make_pair(b,t));
	}
	sort(ss.begin(), ss.end());
	ll tot=0LL;
	ll ans=0LL;
	set<pair<int, int>> st;
	st.clear();
	for (int i = n-1; i >= 0; --i) {
		ll len=ss[i].second+tot;
		ans=max(ans, len*ss[i].first);
		st.insert(make_pair(ss[i].second, i));
		tot += ss[i].second;
		if (st.size()>k-1) {
			tot -= (*st.begin()).first;
			st.erase(st.begin());
		}
	}
	cout<<ans<<endl;
	return 0;
}
