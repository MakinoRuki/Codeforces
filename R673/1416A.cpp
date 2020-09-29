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
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
struct node {
	int tot;
	node* next[2];
	node() {
		tot=0;
		for (int i = 0; i < 2; ++i) {
			next[i]=NULL;
		}
	}
};
ll cntt[40];
ll cnt[40];
ll cnt0[40];
ll cnt1[40];
void insert(node* root, int x) {
	for (int i = 30; i>=0; --i) {
		int bit=0;
		if ((1<<i) & x) {
			bit=1;
		}
		if (root->next[1]) {
			cntt[i] += root->next[1]->tot;
		}
		if (root->next[0]) {
			cntt[i] += root->next[0]->tot;
		}
		if (!bit) {
			if (root->next[1]) {
				cnt[i] += root->next[1]->tot;
			}
		}
		if (!root->next[bit]) {
			root->next[bit]=new node();
		}
		root=root->next[bit];
		if (bit) {
			cnt1[i] += root->tot;
		} else {
			cnt0[i] += root->tot;
		}
		root->tot++;
	}
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(cntt, 0, sizeof(cntt));
	memset(cnt, 0, sizeof(cnt));
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt0, 0, sizeof(cnt0));
	node* root=new node();
	for (int i = 1; i <= n; ++i) {
		insert(root, a[i]);
	}
	ll x=0;
	ll num=0;
	for (int i = 30; i >= 0; --i) {
		ll z=cnt[i];
		ll zt=cntt[i];
		ll z0=cnt0[i];
		ll z1=cnt1[i];
	//	if (i==3) cout<<"num="<<cnt[i]<<" "<<zt<<" "<<cnt0[i]<<" "<<cnt1[i]<<endl;
		ll z2=zt-z-z0-z1;
		if (z>z2) {
			x |= (1LL<<i);
			num += z2;
		} else {
			num += z;
		}
	//	cout<<"i="<<i<<" "<<num<<endl;
	}
	printf("%lld %lld\n", num, x);
	return 0;
}
