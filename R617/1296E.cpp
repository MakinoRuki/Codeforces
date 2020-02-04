#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#define dv 7
#define N 200005
using namespace std;
typedef long long ll;
int n;
string s;
int main() {
	cin>>n;
	cin>>s;
	vector<int> ans(n, 0);
	vector<int> pick(26, 0);
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		int x = s[i] - 'a';
		int res =0;
		for (int j = x + 1; j < 26; ++j) {
			res |= pick[j];
		}
		for (int j = 0; j < 26; ++j) {
			if ((1<<j) & res) continue;
			pick[x] |= (1<<j);
			ans[i] = j;
			cnt[j]++;
			break;
		}
	}
	int tot=0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i]) tot++;
	}
	cout<<tot<<endl;
	for (int i = 0; i < n; ++i) {
		cout<<ans[i]+1;
		if (i < n-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
