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
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
vector<int> pts[N];
int cnt[N][N];
int cnt2[N];
int main() {
	cin>>n>>q;
	for (int i = 1; i <= n; ++i) {
		pts[i].clear();
	}
	memset(cnt, 0, sizeof(cnt));
	memset(cnt2, 0, sizeof(cnt2));
	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		for (int j = l; j <= r; ++j) {
			if (pts[j].size()<=2) {
				pts[j].push_back(i);
			}
		}
	}
	int tot=0;
	for (int i = 1; i <= n; ++i) {
		if (pts[i].size() > 0) {
			tot++;
		}
	//	cout<<i<<" "<<pts[i].size()<<endl;
		if (pts[i].size()==2) {
			int u=pts[i][0];
			int v=pts[i][1];
			cnt[u][v]++;
			cnt[v][u]++;
		} else if (pts[i].size()==1) {
			int u = pts[i][0];
			cnt2[u]++;
		}
	}
	//cout<<"x="<<cnt2[4]<<endl;
	int ans=0;
	for (int i = 1; i <= q; ++i) {
		for (int j = 1; j <= q; ++j) {
			if (i==j) continue;
		//	cout<<i<<" "<<j<<" "<<cnt2[i]<<" "<<cnt2[j]<<" "<<cnt[i][j]<<endl;
			ans = max(ans, tot-cnt2[i]-cnt2[j]-cnt[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
