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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k, m;
vector<int> ids[N];
int a[N];
int col[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			ids[i].clear();
			col[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			ids[a[i]].push_back(i);
		}
		int ans=0;
		for (int i = 1; i <= n; ++i) {
			if (ids[i].size() > 0) {
				ans += min((int)ids[i].size(), k);
			}
		}
		ans = ans/k*k;
		// set<pair<int,int>> ss;
		// ss.clear();
		// for (int i = 1; i <= n; ++i) {
		// 	if (ids[i].size() > 0) {
		// 		ss.insert(make_pair((int)ids[i].size(), i));
		// 	}
		// }
		// int tot=0;
		// int ans=0, num=0;
		// for (int i = 1; i <= k; ++i) {
		// 	while(!ss.empty() && (*ss.begin()).first < i) {
		// 		ss.erase(ss.begin());
		// 	}
		// 	tot += (int)ss.size();
		// 	if (tot / i * i > ans) {
		// 		ans = tot/i*i;
		// 		num = i;
		// 	}
		// }

	//	cout<<num<<" "<<ans<<endl;
		int cnt=0;
		int cur=1;
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			if (ids[i].size() > 0) {
				rk.push_back(make_pair((int)ids[i].size(), i));
			}
		}
	//	cout<<"sz="<<rk.size()<<endl;
		sort(rk.begin(), rk.end());
		reverse(rk.begin(), rk.end());
		for (int i = 0; i < rk.size(); ++i) {
		//	cout<<i<<" "<<rk[i].second<<" "<<cnt<<endl;
			if (cnt >= ans) {
				break;
			}
			int sz=rk[i].first;
			int id = rk[i].second;
			int det = min(k, sz);
			for (int j = 1; j <= det; ++j) {
				if (cnt >= ans) break;
				col[ids[id][j-1]] = cur++;
				if (cur > k) cur=1;
				cnt++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", col[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
