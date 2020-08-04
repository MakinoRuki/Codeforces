#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 200005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n;
int p[N], c[N];
bool vis[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &c[i]);
		}
		vector<vector<int>> pos;
		pos.clear();
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				vector<int> tmp;
				tmp.clear();
				int cur=i;
				while(true) {
					tmp.push_back(cur);
					vis[cur] = true;
					cur = p[cur];
					if (cur == i) break;
				}
				pos.push_back(tmp);
			}
		}
		int ans= inf;
		for (int i = 0; i < pos.size(); ++i) {
			vector<int> v = pos[i];
			int len = v.size();
			vector<int> ds;
			ds.clear();
			for (int j = 1; j * j <= len; ++j) {
				if (len%j==0) {
					ds.push_back(j);
					if (len/j!=j) ds.push_back(len/j);
				}
			}
			for (int j = 0; j < ds.size(); ++j) {
				int d = ds[j];
				for (int x = 0; x < d; ++x) {
					int cc = -1;
					int cur = x;
					bool ok = true;
					while(true) {
						int id = v[cur];
						if (cc < 0) cc = c[id];
						else if (cc != c[id]) {
							ok = false;
							break;
						}
						cur = (cur + d)%len;
						if (cur == x) break;
					}
					if (ok) {
						ans = min(ans, d);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}
