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
#include <queue>
#define N 1000005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int s, k;
int a[N];
int BIT[N];
int lowbit(int x) {
	return x&(-x);
}
void update(int pos, int val) {
	while(pos <= n) {
		BIT[pos] += val;
		pos += lowbit(pos);
	}
}
int query(int pos) {
	int res=0;
	while(pos) {
		res += BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	memset(BIT, 0, sizeof(BIT));
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ll tot=0LL;
	for (int i = 1; i <= n; ++i) {
		ll det=query(n)-query(a[i]);
		update(a[i],1);
		tot += det;
	}
	if (n%2) {
		if (tot%2) cout<<"Petr"<<endl;
		else cout<<"Um_nik"<<endl;
	} else {
		if (tot%2) cout<<"Um_nik"<<endl;
		else cout<<"Petr"<<endl;
	}
	return 0;
}
