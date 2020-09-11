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
#define N 1005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int c[N];
int s[N];
int main() {
	cin>>n;
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
		string ss;
		cin>>ss;
		sort(ss.begin(), ss.end());
		for (int j = 0; j < ss.size(); ++j) {
			s[i] |= (1<<(ss[j]-'A'));
		}
	}
	int dp[10];
	for (int i = 0; i < 8; ++i) {
		dp[i] = inf;
	}
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 7; j >= 0; --j) {
			if (dp[j] < inf) {
				dp[j|s[i+1]] = min(dp[j|s[i+1]], dp[j]+c[i+1]);
			}
		}
	}
	if (dp[7] >= inf) cout<<-1<<endl;
	else cout<<dp[7]<<endl;
	return 0;
}
