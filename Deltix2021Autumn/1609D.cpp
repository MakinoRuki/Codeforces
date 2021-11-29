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
#define M 1000005
#define N 2000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
string s;
int t;
int n, q, m, k, e;
int a[N];
int par[N];
int cnt[N];
vector<pair<int,int>> es;
int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}
int main() {
	cin>>n>>q;
	es.clear();
	while(q-->0) {
		int x,y;
		scanf("%d%d", &x, &y);
		es.push_back(make_pair(x,y));
		for (int i = 1; i <= n; ++i) {
			par[i] = i;
			cnt[i] = 1;
		}
		int rm = 0;
		for (int i = 0; i < es.size(); ++i) {
			x = es[i].first;
			y = es[i].second;
			int px = find(x);
			int py = find(y);
			if (px == py) {
				rm++;
			} else {
				cnt[py] += cnt[px];
				par[px] = py;
			}
		}
		vector<int> rk;
		rk.clear();
		for (int i =1; i <= n; ++i) {
			par[i] = find(i);
			if (par[i] == i) {
				rk.push_back(cnt[i]);
			}
		}
		sort(rk.begin(), rk.end());
		reverse(rk.begin(), rk.end());
		int ans = 0;
		for (int i = 0; i < rk.size(); ++i) {
			ans += rk[i];
			if (rm > 0) {
				rm--;
			} else {
				break;
			}
		}
		printf("%d\n", ans-1);
	}
  return 0;
}

