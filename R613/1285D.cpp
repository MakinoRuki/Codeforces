#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
typedef long long ll;
int n;
int a[N];
struct node {
	bool has;
	node* nxt[2];
	node() {
		has = false;
		nxt[0] = nxt[1] = NULL;
	}
};
node* root;
ll ans;
void insert(int x) {
	node* cur = root;
	for (int i = 30; i >= 0; --i) {
		if ((1<<i) & x) {
			if (!cur->nxt[1]) {
				cur->nxt[1] = new node();
			}
			cur = cur->nxt[1];
		} else {
			if (!cur->nxt[0]) {
				cur->nxt[0] = new node();
			}
			cur = cur->nxt[0];
		}
	}
	cur->has = true;
}
void dfs(node* r, int cur, ll sum) {
	if (cur < 0) {
		if (ans < 0) ans = sum;
		else ans = min(ans, sum);
		return;
	}
	if (r->nxt[0] && r->nxt[1]) {
		dfs(r->nxt[0], cur-1, sum | (1<<cur));
		dfs(r->nxt[1], cur-1, sum | (1<<cur));
	} else if (r->nxt[0] && !r->nxt[1]) {
		dfs(r->nxt[0], cur-1, sum);
	} else if (!r->nxt[0] && r->nxt[1]) {
		dfs(r->nxt[1], cur-1, sum);
	}
}
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	root = new node();
	for (int i = 0; i < n; ++i) {
		insert(a[i]);
	}
	ans = -1;
	dfs(root,30, 0);
	cout<<ans<<endl;
	return 0;
}
