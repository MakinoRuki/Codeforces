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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int a[N];
int b[N];
vector<int> edges[N];
int p[N];
int dis[N];
int ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		int rt = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
			if (b[i] == i) {
				rt = i;
			}
			edges[b[i]].push_back(i);
		}
		for (int i= 1; i <=n; ++i) {
			scanf("%d", &p[i]);
		}
		dis[rt] = 0;
		set<int> ss;
		ss.clear();
		ss.insert(rt);
		int cur=0;
		int i;
		for (i = 1; i <= n; ++i) {
			if (ss.find(p[i]) == ss.end()) {
				break;
			}
			ss.erase(p[i]);
			dis[p[i]] = cur;
			ans[p[i]] = cur - dis[b[p[i]]];
			cur++;
			for (int j = 0; j < edges[p[i]].size(); ++j) {
				ss.insert(edges[p[i]][j]);
			}
		}
		if (i <= n) {
			puts("-1");
		} else {
			for (int i = 1; i <= n; ++i) {
				printf("%d", ans[i]);
				if (i < n) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}

