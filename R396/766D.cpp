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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
int par[N];
int res[N];
map<string, int> mp;
int find(int x) {
	if (x == par[x]) {
		return x;
	}
	int p = par[x];
	int v = find(par[x]);
	res[x] ^= res[p];
	par[x] = v;
	return v; 
}
int main() {
	cin>>n>>m>>q;
	mp.clear();
	for (int i = 1; i <= n; ++i) {
		string s;
		cin>>s;
		mp[s] = i;
	}
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		res[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int tp;
		scanf("%d", &tp);
		string x, y;
		cin>>x>>y;
		int idx = mp[x];
		int idy = mp[y];
		int px = find(idx);
		int py = find(idy);
		if (px == py) {
			if (res[idx] == res[idy] && tp == 2) {
				puts("NO");
			} else if (res[idx] != res[idy] && tp == 1) {
				puts("NO");
			} else {
				puts("YES");
			}
		} else {
			int res1 = res[idx];
			int res2 = res[idy];
			if (tp == 1) {
				res[px] = res1 ^ res2;
				par[px] = py;
			} else {
				res[px] = !(res1 ^ res2);
				par[px] = py;
			}
			puts("YES");
		}
	}
	while(q-->0) {
		string x, y;
		cin>>x>>y;
		int idx = mp[x];
		int idy = mp[y];
		int px = find(idx);
		int py = find(idy);
		if (px == py) {
			if (res[idx] == res[idy]) {
				puts("1");
			} else {
				puts("2");
			}
		} else {
			puts("3");
		}
	}
  return 0;
}
