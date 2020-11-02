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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
string s;
int main() {
	cin>>n>>s;
	unordered_set<int> ss;
	ss.clear();
	int ans=0;
	for (int i = 0; i < n; ++i) {
		if (s[i]>='A' && s[i]<='Z') {
			ss.clear();
		} else {
			ss.insert(s[i]-'a');
			ans=max(ans, (int)ss.size());
		}
	}
	cout<<ans<<endl;
	return 0;
}
