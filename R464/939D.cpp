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
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string s,t;
int par[27];
int find(int u) {
	return u==par[u]?u:par[u]=find(par[u]);
}
int main() {
	cin>>n;
	cin>>s>>t;
	for (int i = 0; i < 26; ++i) {
		par[i]=i;
	}
	vector<pair<int,int>> ans;
	ans.clear();
	for (int i = 0; i < n; ++i) {
		int c1=s[i]-'a';
		int c2=t[i]-'a';
		int p1=find(c1);
		int p2=find(c2);
		if (p1!=p2) {
			par[p1]=p2;
			ans.push_back(make_pair(c1,c2));
		}
	}
	cout<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); ++i) {
		printf("%c %c\n", ans[i].first+'a', ans[i].second+'a');
	}
	return 0;
}
