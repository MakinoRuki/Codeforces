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
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string s;
struct node {
	bool ok;
	node* next[26];
	node() {
		ok=false;
		for (int i = 0; i < 26; ++i) {
			next[i]=NULL;
		}
	}
};
node* root;
multiset<int> dfs(node* cur, int dep) {
	multiset<int> res;
	for (int i = 0; i < 26; ++i) {
		if (cur->next[i]) {
			auto tmp=dfs(cur->next[i], dep+1);
			if (res.size() < tmp.size()) {
				for (auto itr : res) {
					tmp.insert(itr);
				}
				res=tmp;
			} else {
				for (auto itr : tmp) {
					res.insert(itr);
				}
			}
		}
	}
	if (dep==0) {
		return res;
	}
	if (cur->ok) {
		res.insert(dep);
	} else {
		res.erase(--res.end());
		res.insert(dep);
	}
	return res;
}
void insert(node* root, string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if (!root->next[s[i]-'a']) {
			root->next[s[i]-'a'] = new node();
		}
		root=root->next[s[i]-'a'];
	}
	root->ok=true;
}
int main() {
	cin>>n;
	root=new node();
	for (int i = 0; i < n; ++i) {
		cin>>s;
		insert(root, s);
	}
	auto res = dfs(root,0);
	ll tot=0LL;
	for (auto itr : res) {
		tot += itr;
	}
	cout<<tot<<endl;
	return 0;
}
