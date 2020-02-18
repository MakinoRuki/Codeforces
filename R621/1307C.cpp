#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
string s;
int n;
int cnt[N][26];
ll num1[26];
ll num2[26][26];
int main() {
	cin>>s;
	int n = s.size();
	memset(cnt, 0, sizeof(cnt));
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	for (int i = n; i >= 1; --i) {
		num1[s[i-1]-'a']++;
		for (int j = 0; j < 26; ++j) {
			cnt[i][j] = cnt[i+1][j];
		}
		cnt[i][s[i-1]-'a']++;
	}
	ll ans=0LL;
	for (int i = 0; i < 26; ++i) {
		ans = max(ans, num1[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j) {
			num2[s[i-1]-'a'][j] += (ll)cnt[i+1][j];
		}
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			ans = max(ans, num2[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
