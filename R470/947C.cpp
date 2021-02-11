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
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N], p[N];
struct node {
	int cnt;
	node* next[2];
	node() {
		cnt=0;
		next[0] = NULL;
		next[1] = NULL;
	}
};
void update(node* root, int x) {
	for (int i = 29; i >= 0; --i) {
		int bit = (((1<<i) & x) > 0);
		if (!root->next[bit]) {
			root->next[bit] = new node();
		}
		root=root->next[bit];
		root->cnt++;
	}
}
int query(node* root, int x) {
	int res = 0;
	for (int i = 29; i >= 0; --i) {
		int bit = (((1<<i) & x) > 0);
		if (root->next[bit] && root->next[bit]->cnt>0) {
			if (bit) res |= (1<<i);
			root=root->next[bit];
			root->cnt--;
		} else {
			bit = !bit;
			if (bit) res |= (1<<i);
			root=root->next[bit];
			root->cnt--;
		}
	}
	return res;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}
	node* root = new node();
	for (int i = 1; i <= n; ++i) {
		update(root, p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int res = query(root, a[i]);
		printf("%d", a[i] ^ res);
		if (i < n) cout<<" ";
		else cout<<endl;
	}
  return 0;
}
