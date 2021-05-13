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
#define M 25
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int cnt[26];
bool has[26];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		string s;
		cin>>s;
		memset(has, false, sizeof(has));
		memset(cnt, 0, sizeof(cnt));
		string ans="";
		n = s.size();
		for (int i = 0; i < n; ++i) {
			cnt[s[i]-'a']++;
		}
		for (int i = 0; i < n; ++i) {
			if (has[s[i]-'a']) {
				cnt[s[i]-'a']--;
				continue;
			}
			while(!ans.empty()) {
				if (s[i] >= ans.back()) {
					int c = ans.back()-'a';
					if (cnt[c] > 1) {
						ans.pop_back();
						cnt[c]--;
						has[c] = false;
					} else {
						break;
					}
				} else {
					break;
				}
			}
			ans.push_back(s[i]);
			has[s[i]-'a']=true;
		}
		cout<<ans<<endl;
	}
  return 0;
}
