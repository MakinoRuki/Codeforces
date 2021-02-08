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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
int t, n, m;
int a[N], b[N];
int c[N];
vector<int> need[N];
int has[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i =1 ; i <= n; ++i) {
			need[i].clear();
			has[i] = -1;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i =1 ; i <= n; ++i) {
			scanf("%d", &b[i]);
			has[b[i]] = i;
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &c[i]);
		}
		for (int i = 1; i <= n; ++i) {
			if (a[i] != b[i]) {
				need[b[i]].push_back(i);
			}
		}
		int id = -1;
		vector<pair<int,int>> ans;
		ans.clear();
		bool ok = true;
		for (int i = m; i >= 1; --i) {
			if (need[c[i]].size() > 0) {
				ans.push_back(make_pair(i, need[c[i]].back()));
				id = need[c[i]].back();
				need[c[i]].pop_back();
			} else {
				if (has[c[i]] >= 1) {
					ans.push_back(make_pair(i, has[c[i]]));
					id = has[c[i]];
				} else {
					if (id > 0) {
						ans.push_back(make_pair(i, id));
					} else {
						ok=false;
						break;
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (need[i].size() > 0) {
				ok=false;
				break;
			}
		}
		if (!ok) {
			puts("NO");
		} else {
			puts("YES");
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d", ans[i].second);
				if (i <ans.size()-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}
