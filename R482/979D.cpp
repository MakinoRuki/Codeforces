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
#define N 200005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
struct node {
	int minv;
	node* next[2];
	node() {
		minv=inf;
		next[0]=NULL;
		next[1]=NULL;
	}
};
node* a[N];
void update(int id, int v) {
	auto root=a[id];
	for (int i = 20; i >= 0; --i) {
		int n = 0;
		if ((1<<i)&v) n=1;
		if (!root->next[n]) {
			root->next[n]= new node();
		}
		root=root->next[n];
		root->minv=min(root->minv, v);
	}
}
int search(int id, int x, int ub) {
	auto root=a[id];
	for (int i = 20; i >= 0; --i) {
		int n=0;
		if ((1<<i)&x) n=1;
		if (root->next[!n] && root->next[!n]->minv <= ub) {
			root=root->next[!n];
		} else {
			if (!root->next[n]) {
				return -1;
			}
			root=root->next[n];
		}
	}
	if (!root) return -1;
	if (root->minv > ub) return -1;
	return root->minv;
}
int main() {
	cin>>q;
	for (int i = 1; i <= 100000; ++i) {
		a[i]=new node();
	}
	for (int i = 1; i <= q; ++i) {
		int t;
		scanf("%d", &t);
		if (t==1) {
			int u;
			scanf("%d", &u);
			for (int i = 1; i * i <= u; ++i) {
				if (u%i) continue;
				update(i, u);
				if (u/i != i) {
					update(u/i, u);
				}
			}
		} else {
			int x,k,s;
			scanf("%d%d%d",&x,&k,&s);
			if (x%k!=0) {
				cout<<-1<<endl;
			} else {
				if (s-x<1) {
					cout<<-1<<endl;
				} else {
					auto res=search(k, x, s-x);
					cout<<res<<endl;
				}	
			}
		}
	}
	return 0;
}
