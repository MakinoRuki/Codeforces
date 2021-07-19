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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int cnt[N][26];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j < 26; ++j) {
				cnt[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; ++i) {
			string s;
			cin>>s;
			for (int j = 0; j < m; ++j) {
				cnt[j+1][s[j]-'a']++;
			}
		}
		for (int i = 1; i < n; ++i) {
			string s;
			cin>>s;
			for (int j = 0; j < m; ++j) {
				cnt[j+1][s[j]-'a']--;
			}
		}
		string ans="";
		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j < 26; ++j) {
				if (cnt[i][j] > 0) {
					ans.push_back('a'+j);
					break;
				}
			}
		}
		cout<<ans<<endl;
		fflush(stdout);
	}
  return 0;
}
