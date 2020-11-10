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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m;
int a[N];
int ans[N];
bool vis[2*N];
struct node {
	int tot;
	node* next[2];
	node() {
		tot=0;
		next[0]=NULL;
		next[1]=NULL;
	}
};
void insert(node* root, int x) {
	for (int i = 20; i >= 0; --i) {
		int bit=(x&(1<<i))>0;
		if (!root->next[bit]) {
			root->next[bit]=new node();
		}
		root=root->next[bit];
		root->tot++;
	}
}
int query(node* root, int x) {
	int res=0;
	for (int i = 20; i >= 0; --i) {
		int bit=(x&(1<<i))>0;
		if (!root->next[bit]) {
			return res;
		}
		if (root->next[bit]->tot == (1<<i)) {
			res |= (1<<i);
			if (root->next[!bit]) {
				root=root->next[!bit];
			} else {
				return res;
			}
		} else {
			root=root->next[bit];
		}
	}
	return res;
}
int main() {
	cin>>n>>m;
	memset(vis, false, sizeof(vis));
	node* root=new node();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (!vis[a[i]]) {
			insert(root, a[i]);
			vis[a[i]]=true;
		}
	}
	for (int i = 1; i <= n; ++i) {
	//	cout<<"i="<<i<<endl;
		ans[a[i]] = query(root, a[i]);
	//	cout<<"i2="<<i<<endl;
	}
	int x=0;
	for (int i = 1; i <= m; ++i) {
		int x2;
		scanf("%d", &x2);
		x ^= x2;
		if (!vis[x]) {
			cout<<0<<endl;
		} else {
			printf("%d\n", ans[x]);
		}
	}
	return 0;
}
