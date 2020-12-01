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
int a[N];
struct node {
	int cnt;
	node* next[2];
	node() {
		cnt=0;
		for (int i = 0; i < 2; ++i) {
			next[i]=NULL;
		}
	}
};
int ans;
void insert(node* root, int x) {
	for (int i = 30; i >= 0; --i) {
		int bit=(x&(1<<i))>0;
		if (!root->next[bit]) {
			root->next[bit]=new node();
		}
		root=root->next[bit];
		root->cnt++;
	}
}
int dfs(node* root) {
	if (!root) return 0;
	if (!root->next[0] && !root->next[1]) {
		return root->cnt;
	}
	if (!root->next[0]) {
		return dfs(root->next[1]);
	} else {
		if (!root->next[1]) {
			return dfs(root->next[0]);
		}
		int lr=dfs(root->next[0]);
		int rr=dfs(root->next[1]);
		return max(lr+1, rr+1);
	}
}
int main() {
	cin>>n;
	node* root=new node();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		insert(root, a[i]);
	}
	int ans = dfs(root);
	cout<<n-ans<<endl;
	return 0;
}
