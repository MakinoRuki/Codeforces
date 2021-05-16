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
#define N 2000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
bool pm[N];
int a[N];
int vis[N];
int main() {
// 	memset(pm, false, sizeof(pm));
// //	int cnt=0;
// 	for (int i = 2; i*i <= 2000000; ++i) {
// 		if (!pm[i]) {
// 			for (int j = i*i; j <= 2000000; j+=i) {
// 				pm[j] = true;
// 			}
// 		}
// 	}
// 	vector<int> ps;
// 	ps.clear();
	// for (int i = 2; i <= 2000000; ++i) {
	// 	if (!pm[i]) {
	// 		//cnt++;
	// 	}
	// }
//	cout<<"cnt="<<cnt<<endl;
	cin>>t;
//	memset(cnt, 0, sizeof(cnt));
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		int id = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (i == 1 || a[i] < a[id]) {
				id = i;
			}
		}
		vector<pair<pair<int,int>,pair<int,int>>> ans;
		ans.clear();
		for (int j = id-1; j >= 1; --j) {
			int det = id-j;
			if (det % 2) {
				ans.push_back(make_pair(make_pair(id,j), make_pair(a[id],a[id]+1)));
			} else {
				ans.push_back(make_pair(make_pair(id,j), make_pair(a[id], a[id])));
			}
		}
		for (int j = id+1; j <= n; ++j) {
			int det = j-id;
			if (det % 2) {
				ans.push_back(make_pair(make_pair(id,j), make_pair(a[id],a[id]+1)));
			} else {
				ans.push_back(make_pair(make_pair(id,j), make_pair(a[id], a[id])));
			}
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
		}
	}
  return 0;
}
