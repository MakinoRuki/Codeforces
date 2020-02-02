#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q, n;
int a[N];
int dp[N];
int l[N], r[N];
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		cin>>n;
		for (int i =1 ; i <= n; ++i) {
			l[i] = n+1;
			r[i] = 0;
		}
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			cin>>a[i];
			ss.insert(a[i]);
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}
		int ans = 1;
		int cur=1;
		int pre = r[*ss.begin()];
		for (auto itr = ss.begin(); itr != ss.end(); ++itr) {
			if (itr == ss.begin()) continue;
			if (l[*itr] <= pre) {
				cur=1;
			} else {
				cur++;
			}
			pre = r[*itr];
			ans = max(ans, cur);
		}
		cout<<ss.size()-ans<<endl;
	}
	return 0;
}
