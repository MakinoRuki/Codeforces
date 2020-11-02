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
#define N 200002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
string s;
int sum[26][N];
int getres(int c, int num) {
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r)/2;
		if (sum[c][mid] >= num) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return r;
}
int main() {
	cin>>n>>s;
	cin>>m;
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j <= n; ++j) {
			sum[i][j] = sum[i][j-1]  + (s[j-1]==i+'a');
		}
	}
	for (int i = 1; i <= m; ++i) {
		string t;
		cin>>t;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < t.size(); ++j) {
			cnt[t[j]-'a']++;
		}
		int res=0;
		for (int j = 0; j < 26; ++j) {
			if (cnt[j]==0) continue;
			res=max(res, getres(j, cnt[j]));
		}
		printf("%d\n", res);
	}
	return 0;
}
