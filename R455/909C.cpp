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
#define eps 1e-7
#define M 20005
#define N 5005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m;
int dp[2][N];
string p;
int lowbit(int x) {
	return x&(-x);
}
void update(int now, int id, int val) {
	while(id <= n) {
		dp[now][id] = (dp[now][id]+val)%mod;
		id += lowbit(id);
	}
}
int query(int now, int id) {
	int res=0;
	while(id) {
		res = (res+dp[now][id])%mod;
		id -= lowbit(id);
	}
	return res;
}
int main() {
	cin>>n;
	p.clear();
	char s[2];
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		p.push_back(s[0]);
	}
//	memset(BIT, 0, sizeof(BIT));
	int now=0;
	update(now, 1, 1);
	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[now^1][j]=0;
		}
		int tot=query(now, n);
		for (int j = 1; j <= i+1; ++j) {
			int res=(tot-query(now, j-1)+mod)%mod;
	//		cout<<i<<" "<<j<<" "<<res<<endl;
			if (p[i]=='f') {
				update(now^1, j+1, res);
				update(now^1, j, -res);
			//	dp[now^1][j+1]=(dp[now^1][j+1]+dp[now][j])%mod;
			} else {
				update(now^1, j, res);
			}
		//	cout<<"fuck="<<i<<" "<<j<<" "<<query(0, 2)<<endl;
		}
		now^=1;
	}
//	cout<<"tot="<<query(now, 2)<<endl;
	if (p[n-1]=='f') cout<<0<<endl;
	else {
		int ans=0;
		int tot=query(now, n);
		for (int i = 1; i <= n; ++i) {
	//		cout<<"i="<<i<<" "<<query(now, i-1)<<endl;
			ans=(ans+(tot-query(now,i-1)+mod)%mod)%mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
