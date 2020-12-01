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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
ll w;
ll ww[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%lld", &n, &w);
		vector<pair<ll,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &ww[i]);
			rk.push_back(make_pair(ww[i], i));
		}
		sort(rk.begin(), rk.end());
		ll tot=0LL;
		vector<int> ids;
		ids.clear();
		bool ok=true;
		for (int i = 0; i < n; ++i) {
			if (rk[i].first<=w) {
				if (rk[i].first>=(w+1)/2) {
					ids.clear();
					ids.push_back(rk[i].second);
					tot=rk[i].first;
					break;
				} else {
					if (tot >= (w+1)/2) {
						break;
					}
					tot += rk[i].first;
					ids.push_back(rk[i].second);
				}
			} else {
				if (tot>=(w+1)/2) {
					break;
				}
				ok=false;
				break;
			}
		}
		if (!ok || tot<(w+1)/2 || tot>w) {
			cout<<-1<<endl;
		} else {
			printf("%d\n", (int)ids.size());
			for (int i = 0; i < ids.size(); ++i) {
				printf("%d", ids[i]);
				if (i < ids.size()-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
