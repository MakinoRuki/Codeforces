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
#define N 60
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		vector<pair<int, int>> sgs;
		sgs.clear();
		int tot=0;
		int id=-1;
		int cnt=0;
		for (int i = 1; i <= n; ++i) {
			if (a[i]) {
				if (id<0) {
					id=i;
					cnt=1;
				} else {
					cnt++;
				}
			} else {
				if (cnt>0) {
					sgs.push_back(make_pair(id, cnt));
					id=-1;
					cnt=0;
				}
			}
		}
		if (cnt>0) sgs.push_back(make_pair(id, cnt));
		int ans=n;
		for (int i = 0; i < sgs.size(); ++i) {
			int sum=0;
			for (int j = i-1; j >= 0; --j) {
				sum += sgs[j+1].first - (sgs[j].first+sgs[j].second-1)-1;
			}
			for (int j = i+1; j < sgs.size(); ++j) {
				sum += sgs[j].first - (sgs[j-1].first+sgs[j-1].second-1)-1;
			}
			ans=min(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}
