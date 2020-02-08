#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#define N 300005
using namespace std;
typedef long long ll;
string s;
int n;
int dp[(1<<20)+3];
int main() {
	string s;
	cin>>s;
	n = s.size();
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i) {
		int st = 0;
		int cnt=0;
		for (int j = 0; j < 20; ++j) {
			if (i + j >= n) break;
			if ((1<<(s[i+j]-'a')) & st) break;
			st |= (1<<(s[i+j]-'a'));
			cnt++;
			dp[st] = cnt;
		}
	}
	for (int i = 0; i < (1<<20); ++i) {
		for (int j = 0; j < 20; ++j) {
			if ((1<<j) & i) {
				//if (!has[i^(1<<j)]) continue;
				dp[i] = max(dp[i], dp[i ^ (1<<j)]);
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		int st = 0;
		for (int j = 0; j < 20; ++j) {
			if (i + j >= n) break;
			if ((1<<(s[i+j]-'a')) & st) break;
			st |= (1<<(s[i+j]-'a'));
			ans = max(ans, j+1 + dp[((1<<20)-1) ^ st]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
