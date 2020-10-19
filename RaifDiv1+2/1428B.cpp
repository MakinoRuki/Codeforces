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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
string s;
bool ok[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		set<int> ss;
		ss.clear();
		for (int i = 0; i < n; ++i) {
			if (s[i]=='-' || s[i]=='>') {
				ss.insert(i);
			} else {
				ss.clear();
			}
		}
		memset(ok, false, sizeof(ok));
		int ans=0;
		for (int i = 0; i < n; ++i) {
			if (ss.find(i) != ss.end()) {
				ok[i]=true;
				ss.erase(i);
			}
			if (s[i]=='<') {
				ss.clear();
			}
		}
		ss.clear();
		for (int i = n-1; i >= 0; --i) {
			if (s[i]=='>') {
				ss.clear();
			} else {
				ss.insert(i);
			}
		}
		for (int i=n-1; i >= 0; --i) {
			if (ss.find(i) != ss.end()) {
				ok[i]=true;
				ss.erase(i);
			}
			if (s[i]=='>') {
				ss.clear();
			}
		}
		for (int i = 0; i < n; ++i) {
			if (s[i]=='-' || s[(i-1+n)%n]=='-') {
				ok[i]=true;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (ok[i]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
