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
#define N 1502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,q;
string s;
int dp[N][N][2];
int ans[26][N];
int main() {
	cin>>n>>s;
	memset(dp, -1, sizeof(dp));
	memset(ans, 0, sizeof(ans));
	for (int c = 0; c < 26; ++c) {
		int sum[N];
		for (int i = 0; i <= n; ++i) {
			sum[i]=0;
		}
		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i-1];
			if (s[i-1]-'a'==c) {
				sum[i]++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				int num=sum[j]-sum[i-1];
				int det=j-i+1-num;
				ans[c][det] = max(ans[c][det], j-i+1);
				// if (c+'a'=='o' && ans['o'-'a'][1]==4) {
				// 	cout<<i<<" "<<j<<" "<<num<<endl;
				// }
			}
		}
		for (int i = 1; i <= n; ++i) {
			ans[c][i] = max(ans[c][i], ans[c][i-1]);
		}
	}
	cin>>q;
	while(q-->0) {
		int m;
		string c;
		scanf("%d", &m);
		cin>>c;
		printf("%d\n", ans[c[0]-'a'][m]);
	}
	return 0;
}
