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
#define N 300005
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
int cnt[M];
ll bit[N];
int lowbit(int x) {
	return x&(-x);
}
void update(int pos, ll v) {
	while(pos <= n) {
		bit[pos] += v;
		pos += lowbit(pos);
	}
}
ll query(int pos) {
	ll res= 0LL;
	while(pos) {
		res += bit[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int getres(int x) {
	int num=0;
	while(x > 2) {
		num++;
		x = cnt[x];
	}
	return num;
}
int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}
int main() {
	for (int i = 1; i <= 1000000; ++i) {
		vector<int> v;
		v.clear();
		int x=i;
		int y=1;
		for (int j = 2; j*j <= x; ++j) {
			if (x%j == 0) {
				int cnt=0;
				while(x%j ==0) {
					x/=j;
					cnt++;
				}
				y*=(cnt+1);
			}
		}
		if (x>1) y*=2;
		cnt[i] = y;
	}
	cin>>n>>m;
	set<int> ss;
	ss.clear();
	memset(bit, 0, sizeof(bit));
	for (int i =1; i <= n; ++i) {
		scanf("%d", &a[i]);
		update(i, a[i]);
	}
	par[n+1] = n+1;
	for (int i = n; i >= 1; --i) {
		if (a[i] > 1) par[i] = i;
		else par[i] = par[i+1];
	}
	while(m-->0) {
		int ty, l, r;
		scanf("%d%d%d", &ty, &l, &r);
		if (ty == 1) {
			for (int i = find(l); i <= r; i = find(i+1)) {
				update(i, -a[i] + cnt[a[i]]);
				a[i] = cnt[a[i]];
				if (a[i] <= 2) par[i] = par[i+1];
			}
		} else {
			ll res = query(r) - query(l-1);
			printf("%lld\n", res);
		}
	}
  return 0;
}

