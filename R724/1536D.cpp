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
#define M 10005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int b[N];
int idx[N];
int bit[N];
int cnt;
int lowbit(int x) {
	return x&(-x);
}
void update(int id) {
	while(id <= cnt) {
		bit[id]++;
		id += lowbit(id);
	}
}
int query(int id) {
	int res=0;
	while(id > 0) {
		res += bit[id];
		id -= lowbit(id);
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
			rk.push_back(make_pair(b[i],i));
			bit[i] = 0;
		}
		sort(rk.begin(), rk.end());
		cnt=0;
		set<int> ss;
		ss.clear();
		for (int i = 0; i < rk.size(); ++i) {
			if (i == 0 || rk[i].first != rk[i-1].first) {
				cnt++;
			}
			idx[rk[i].second] = cnt;
		}
		int ln = 0, rn = 0;
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
		//	cout<<"i="<<i<<endl;
			int id = idx[i];
			int res = query(id-1);
			int res2 = (int)ss.size()-res;
			if (ss.find(id) != ss.end()) {
				res2--;
				if (res+ln != res2+rn && abs(res+ln-res2-rn) != 2) {
					ok=false;
					break;
				}
				if (res+ln < res2+rn) {
					ln += 2;
				} else if (res+ln > res2+rn) {
					rn += 2;
				} else {
					ln++;
					rn++;
				}
			//	cout<<"x="<<ln<<" "<<rn<<endl;
			} else {
				if (i > 1) {
					if (ln + res - (res2+rn) == 1) {
						rn++;
					} else if (res2+rn-(ln+res) == 1) {
						ln++;
					} else {
						ok=false;
						break;
					}
				}
				ss.insert(id);
				update(id);
			//	cout<<"y="<<ln<<" "<<rn<<endl;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
  return 0;
}
