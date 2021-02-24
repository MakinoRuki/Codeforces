
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
#define M 52
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
string s, t;
int lm[N], rm[N];
int main() {
	cin>>n>>m;
	cin>>s>>t;
	int j = 0;
	for (int i = 0; i < m; ++i) {
		while(j < n && s[j] != t[i]) {
			j++;
		}
		lm[i] = j;
		j++;
	}
	j = n-1;
	for (int i = m-1; i >= 0; --i) {
		while(j >= 0 && s[j] != t[i]) {
			j--;
		}
		rm[i] = j;
		j--;
	}
	int ans = 0;
	for (int i = 0; i < m-1; ++i) {
		if (lm[i] < rm[i+1]) {
			ans = max(ans, rm[i+1]-lm[i]);
		}
	}
	for (int i = 1; i < m; ++i) {
		ans = max(ans, lm[i]-lm[i-1]);
	}
	for (int i = 0; i < m-1; ++i) {
		ans = max(ans, rm[i+1]-rm[i]);
	}
	cout<<ans<<endl;
  return 0;
}
