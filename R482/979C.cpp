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
#define N 300005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, x, y;
vector<int> edges[N];
int sons[N];
bool dfs(int s, int u, int p, int t, ll& cnt) {
	sons[u]=1;
	bool cur=false;
	if (u==t) {
		cur=true;
	}
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v==p) continue;
		bool res=dfs(s, v, u, t, cnt);
		if (res) {
			if (u==s) {
			//	cout<<"u="<<u<<" "<<v<<" "<<sons[v]<<endl;
				cnt = n-sons[v];
			} else {
				cur=true;
			}
		}
		sons[u] += sons[v];
	}
	return cur;
}
int main() {
	cin>>n>>x>>y;
	for (int i = 1; i < n; ++i) {
		int a,b;
		scanf("%d%d", &a,&b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	ll res=(ll)n*(ll)(n-1);
	ll cnt1=0;
	ll cnt2=0;
	memset(sons, 0, sizeof(sons));
	dfs(x, x, 0, y, cnt1);
	memset(sons, 0, sizeof(sons));
	dfs(y, y, 0, x, cnt2);
	res -= cnt1*cnt2;
	cout<<res<<endl;
	return 0;
}
