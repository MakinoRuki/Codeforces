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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
int cnt[N];
bool vis[N];
bool rep[N];
int main() {
	cin>>n;
	memset(cnt, 0, sizeof(cnt));
	memset(rep, false, sizeof(rep));
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	vector<int> ds;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i]==0) {
			ds.push_back(i);
		} else {
			if (cnt[i]>1) {
				rep[i]=true;
			}
		}
	}
	reverse(ds.begin(), ds.end());
	int ans=ds.size();
	for (int i = 1; i <= n; ++i) {
		if (rep[a[i]]) {
			if (vis[a[i]]) {
				cnt[a[i]]--;
				a[i]=ds.back();
				ds.pop_back();
			} else {
				if (ds.empty()) {
					vis[a[i]]=true;
					continue;
				}
				int minv=ds.back();
				if (minv<a[i]) {
					if (cnt[a[i]]==1) {
						vis[a[i]]=true;
						continue;
					}
					cnt[a[i]]--;
					a[i]=minv;
					ds.pop_back();
				} else {
					vis[a[i]]=true;
				}
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) {
		printf("%d", a[i]);
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
