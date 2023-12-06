#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#define N 500005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
struct node {
	int cnt;
	node* nxt[26];
	node() {
		cnt=0;
		for (int i = 0; i < 26; ++i) {
			nxt[i] = NULL;
		}
	}
};
vector<string> ss;
void update(node* root, string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if (root->nxt[s[i]-'a'] == NULL) {
			root->nxt[s[i]-'a'] = new node();
		}
		root=root->nxt[s[i]-'a'];
		root->cnt++;
	}
}
ll query(node* root, string& s) {
	ll res=0LL;
	for (int i = 0; i < s.size(); ++i) {
		if (root->nxt[s[i]-'a']) {
			root = root->nxt[s[i]-'a'];
		} else {
			break;
		}
		res += root->cnt;
	}
	return res;
}
int main() {
  cin>>n;
  node* root=new node();
  ss.clear();
  ll tot = 0LL;
  for (int i = 0; i < n; ++i) {
  	string s;
  	cin>>s;
  	ss.push_back(s);
  	tot += (ll)s.size();
  	update(root, s);
  }
  ll ans= 0LL;
  for (int i = 0; i < n; ++i) {
  	string s2 = ss[i];
  	reverse(s2.begin(), s2.end());
  	ll res = query(root, s2);
  //	cout<<"res="<<i<<" "<<ss[i]<<" "<<res<<endl;
  	ans += (ll)s2.size() * (ll)n + tot;
  	ans -= res*2LL;
  }
  printf("%lld\n", ans);
  return 0;
}
