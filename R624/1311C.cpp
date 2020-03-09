#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int t, n, m;
string s;
int p[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m;
		cin>>s;
		set<pair<int, int>> ps;
		ps.clear();
		for (int i = 1; i <= m; ++i) {
			cin>>p[i];
			ps.insert(make_pair(p[i], i));
		}
		int cnt[27];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i) {
			while(!ps.empty() && (*ps.begin()).first < i) {
				ps.erase(*ps.begin());
			}
			cnt[s[i-1]-'a'] += ps.size() + 1;
		}
		for (int i = 0; i < 26; ++i) {
			cout<<cnt[i];
			if (i < 25) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
