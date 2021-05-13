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
#define M 25
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
vector<int> ids[N];
int cnt[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; ++i) {
			ids[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			cnt[i] = 0;
		}
		vector<int> ans;
		ans.clear();
		for (int i = 1; i <= m; ++i) {
			int k;
			scanf("%d", &k);
			for (int j = 1; j <= k; ++j) {
				int x;
				scanf("%d", &x);
				ids[i].push_back(x);
			}
			ans.push_back(ids[i][0]);
			cnt[ids[i][0]]++;
		}
		int id = -1;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] > (m+1)/2) {
				id = i;
			}
		}
		if (id < 0) {
			puts("YES");
			for (int i = 1; i <= m; ++i) {
				printf("%d", ids[i][0]);
				if (i < m) cout<<" ";
				else cout<<endl;
			}
		} else {
			for (int i = 1; i <= m; ++i) {
				if (cnt[id] <= (m+1)/2) {
					break;
				}
				if (ids[i][0] == id && ids[i].size() > 1) {
					ans[i-1] = ids[i][1];
					cnt[id]--;
				}
			}
			if (cnt[id] > (m+1)/2) {
				puts("NO");
			} else {
				puts("YES");
				for (int i = 0; i < ans.size(); ++i) {
					printf("%d", ans[i]);
					if (i < ans.size()-1) cout<<" ";
					else cout<<endl;
				}
			}
		}
	}
  return 0;
}
