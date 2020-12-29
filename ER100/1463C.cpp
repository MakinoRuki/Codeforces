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
#define N 105
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int r, n;
int t;
int a,b,c;
vector<pair<int,int>> cs;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cs.clear();
		for (int i = 0; i < n; ++i) {
			int x,y;
			scanf("%d%d", &x, &y);
			cs.push_back(make_pair(x,y));
		}
		sort(cs.begin(), cs.end());
		int tot=0;
		ll t1, sx, ex;
		for (int i = 0; i < cs.size(); ++i) {
			if (i==0) {
				t1=cs[i].first;
				sx=0, ex=cs[i].second;
				ll t2 = t1+(ll)abs(ex-sx);
				if (i+1>=cs.size() || t2 <= cs[i+1].first) {
					tot++;
				}
			} else {
				ll t2=t1+(ll)abs(ex-sx);
				if (cs[i].first >= t2) {
					t1=cs[i].first;
					sx=ex;
					ex = cs[i].second;
					t2=t1+(ll)abs(ex-sx);
					if (i+1>=cs.size() || t2 <= cs[i+1].first) {
						tot++;
					}
				} else {
					ll x2=cs[i].second;
					if ((x2 >= sx && x2 <= ex)||(x2>=ex&&x2<=sx)) {
						ll t2=t1+(ll)abs(sx-x2);
						if (t2 >= cs[i].first && (i+1>=cs.size() || t2<=cs[i+1].first)) {
							tot++;
						}
					}
				}
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}
