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
#define N 110
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int cnt[N];
int main() {
	cin>>t;
	for (int cas=1;cas<=t; ++cas) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		vector<int> ans;
		ans.clear();
		for (int i = 0; i <= 100; ++i) {
			if (cnt[i] > 0) {
				ans.push_back(i);
				cnt[i]--;
			}
		}
		for (int i = 0; i <= 100; ++i) {
			if (cnt[i] > 0) {
				for (int j = 1; j <= cnt[i]; ++j) {
					ans.push_back(i);
				}
			}
		}
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d", ans[i]);
			if (i < ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
