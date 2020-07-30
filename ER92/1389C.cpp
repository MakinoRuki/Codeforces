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
#define N 300005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		int cnt[10];
		int n = s.size();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) {
			cnt[s[i]-'0']++;
		}
		int ans = 0;
		for (int i = 0; i < 10; ++i) {
			ans = max(ans, cnt[i]);
		}
		ans = n-ans;
		for (int a = 0; a < 10; ++a) {
			for (int b = 0; b < 10; ++b) {
				if (a==b) continue;
				int len = 0;
				for (int i = 0; i < n; ++i) {
					if (len%2 && s[i]-'0'==b) len++;
					else if (len%2==0 && s[i]-'0'==a) len++;
				}
				if (len%2==0) {
					if (len>0) ans = min(ans, n-len);
				} else {
					if (len-1>0) ans = min(ans, n-len+1);
				}
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}
