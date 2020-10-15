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
int t,n,k;
string s;
int BIT[N];
bool vis[N];
int lowbit(int x) {
	return x&(-x);
}
int query(int id) {
	int tot=0;
	while(id) {
		tot += BIT[id];
		id -= lowbit(id);
	}
	return tot;
}
void update(int id, int v) {
	while(id<=n) {
		BIT[id] += v;
		id += lowbit(id);
	}
}
int main() {
	cin>>n>>s;
	set<int> ps[27];
	memset(BIT, 0, sizeof(BIT));
	for (int i = 0; i < 26; ++i) {
		ps[i].clear();
	}
	ll ans=0LL;
	string t=s;
	memset(vis, false, sizeof(vis));
	int j=1;
	reverse(t.begin(), t.end());
	for (int i = 1; i <= n; ++i) {
		ps[s[i-1]-'a'].insert(i);
	}
	for (int i = 1; i <= n; ++i) {
	//	cout<<"i="<<i<<endl;
		while(j<=n && vis[j]) {
			j++;
		}
		if (s[j-1] == t[i-1]) {
			vis[j] = true;
			ps[s[j-1]-'a'].erase(j);
		} else {
			auto id = *ps[t[i-1]-'a'].begin();
			int det=query(id)-query(j-1);
			det=id-j-det;
			ans += det;
			update(id, 1);
			vis[id]=true;
			ps[t[i-1]-'a'].erase(id);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
