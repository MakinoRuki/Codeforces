#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#define N 300005
using namespace std;
typedef long long ll;
int n, m;
int a[N];
int pos[N];
int BIT[2*N];
int val[2][N];
int lowbit(int x) {
	return x & (-x);
}
void update(int p, int v) {
	while(p <= n+m) {
		BIT[p] += v;
		p += lowbit(p);
	}
}
int query(int p) {
	int res=0;
	while(p) {
		res += BIT[p];
		p -= lowbit(p);
	}
	return res;
}
int main() {
	scanf("%d%d",&n,&m);
	memset(BIT, 0, sizeof(BIT));
	for (int i = 1; i <= n; ++i) {
		pos[i] = m+i;
		update(m+i, 1);
		val[0][i] = i;
		val[1][i] = i;
	}
	int cur = m;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
		val[0][a[i]] = 1;
		val[1][a[i]] = max(val[1][a[i]], query(pos[a[i]]));
		update(pos[a[i]], -1);
		pos[a[i]] = cur;
		cur--;
		update(pos[a[i]], 1);
	}
	for (int i = 1; i <= n; ++i) {
		val[1][i] = max(val[1][i], query(pos[i]));
		cout<<val[0][i]<<" "<<val[1][i]<<endl;
	}
	return 0;
}
