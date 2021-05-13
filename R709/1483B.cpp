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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
int ids[N];
int nxt[N];
int getgcd(int x, int y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		set<int> ss;
		ss.clear();
		int bg = 0;
		for (int i = 1; i <= n; ++i) {
			ids[i] = -1;
			scanf("%d", &a[i]);
		}
		if (n == 1) {
			if (a[n] == 1) {
				cout<<1<<" "<<1<<endl;
			} else {
				puts("0");
			}
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			int j = (i < n ? i+1 : 1);
			if (getgcd(a[i], a[j]) == 1) {
				if (bg <= 0) bg = i;
				ss.insert(i);
				ids[i] = j;
			}
			nxt[i] = j;
		}
		if (bg <= 0) {
			puts("0");
			continue;
		}
		vector<int> ans;
		ans.clear();
		while(true) {
			int x = ids[bg];
			ss.erase(bg);
			ans.push_back(x);
		//	cout<<bg<<" "<<x<<endl;
			int y = nxt[x];
			if (y == bg) {
				if (a[bg] == 1) {
					ans.push_back(bg);
				}
				break;
			}
			if (ids[x] == y) {
				ss.erase(x);
			}
			if (getgcd(a[bg], a[y]) == 1) {
				ss.insert(bg);
				ids[bg] = y;
			}
			nxt[bg] = y;
			if (ss.empty()) break;
			auto itr = ss.upper_bound(bg);
			if (itr == ss.end()) {
				bg = (*ss.begin());
			} else {
				bg = *itr;
			}
		}
		printf("%d", (int)ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			printf(" %d", ans[i]);
		}
		cout<<endl;
	}
  return 0;
}
