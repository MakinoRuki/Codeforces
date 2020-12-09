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
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,q;
int n;
vector<pair<pair<int,int>,int>> segs;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		segs.clear();
		for (int i = 0; i < n; ++i) {
			int l,r;
			scanf("%d%d", &l, &r);
			segs.push_back(make_pair(make_pair(l, r),i));
		}
		sort(segs.begin(), segs.end());
		vector<int> ids;
		ids.clear();
		int b=segs[0].first.first;
		int e=segs[0].first.second;
		ids.push_back(segs[0].second);
		for (int i = 1; i < n; ++i) {
			int x=segs[i].first.first;
			int y=segs[i].first.second;
			if (x<=e && b<=y) {
				b=min(x,b);
				e=max(y,e);
				ids.push_back(segs[i].second);
			} else {
				break;
			}
		}
		if (ids.size() < n) {
			unordered_set<int> ss(ids.begin(), ids.end());
			for (int i = 0; i < n; ++i) {
				if (ss.find(i) == ss.end()) {
					printf("%d", 2);
				} else {
					printf("%d", 1);
				}
				if (i<n-1) cout<<" ";
				else cout<<endl;
			}
		} else {
			cout<<-1<<endl;
		}
	}
	return 0;
}
