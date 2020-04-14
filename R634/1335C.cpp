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
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int t, n;
int a[N];
int cnt[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		memset(cnt, 0, sizeof(cnt));
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			cnt[a[i]]++;
			ss.insert(a[i]);
		}
		int ans=0;
		for (int i = 1; i <= n; ++i) {
			ss.erase(a[i]);
			ans = max(ans, min(cnt[a[i]], (int)ss.size()));
			ss.insert(a[i]);
			ans = max(ans, min(cnt[a[i]]-1, (int)ss.size()));
		}
		cout<<ans<<endl;
	}
	return 0;
}
