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
ll a[N];
ll sum[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		vector<pair<ll,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			rk.push_back(make_pair(a[i], i));
		}
		sort(rk.begin(), rk.end());
		for (int i = 0; i <= n; ++i) {
			sum[i] = 0LL;
		}
		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i-1] + rk[i-1].first;
		}
		vector<int> ids;
		ids.clear();
		ids.push_back(rk.back().second);
		for (int i = n-1; i >= 1; --i) {
			if (sum[i] >= rk[i].first) {
				ids.push_back(rk[i-1].second);
			} else {
				break;
			}
		}
		printf("%d\n", (int)ids.size());
		sort(ids.begin(), ids.end());
		for (int i = 0; i < ids.size(); ++i) {
			printf("%d", ids[i]);
			if (i<ids.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}

