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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int p[N];
int pmax[N][20];
int pos[N];
ll ans;
void dfs(int l, int r) {
	if (l>=r) return;
	int pw=0;
	while((1<<pw)<=(r-l+1)) {
		pw++;
	}
	pw--;
	int id1 = pmax[l][pw];
	int id2 = pmax[r-(1<<pw)+1][pw];
	int id=-1;
	if (id2<0 || (id1>=0 && p[id1]>p[id2])) {
		id=id1;
	} else {
		id=id2;
	}
	// cout<<"x="<<l<<" "<<r<<" "<<id<<endl;
	// cout<<"ans="<<ans<<endl;
	if (id-l<r-id) {
		for (int i = l; i < id; ++i) {
			if (pos[p[id]-p[i]]>id && pos[p[id]-p[i]]<=r) {
				ans++;
			}
		}
	} else {
		for (int i = id+1; i <= r; ++i) {
			if (pos[p[id]-p[i]]<id && pos[p[id]-p[i]]>=l) {
				ans++;
			}
		}
	}
	//cout<<"ans2="<<ans<<endl;
	dfs(l, id-1);
	dfs(id+1, r);
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		pos[p[i]]=i;
	}
	memset(pmax, -1, sizeof(pmax));
	for (int i = 1; i <= n; ++i) {
		pmax[i][0] = i;
	}
	for (int i = 1; (1<<i) <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j+(1<<i)-1<=n) {
				if (pmax[j][i-1]>=0 && (pmax[j][i]<0 || p[pmax[j][i]]<p[pmax[j][i-1]])) {
					pmax[j][i] = pmax[j][i-1];
				}
				if (pmax[j+(1<<(i-1))][i-1]>=0 && (pmax[j][i]<0 || p[pmax[j][i]]<p[pmax[j+(1<<(i-1))][i-1]])) {
					pmax[j][i] = pmax[j+(1<<(i-1))][i-1];
				}
			}
		}
	}
	ans = 0LL;
	dfs(1, n);
	cout<<ans<<endl;
	return 0;
}
