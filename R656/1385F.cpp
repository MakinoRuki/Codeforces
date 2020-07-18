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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n,k;
vector<int> edges[N];
int deg[N];
int ans;
void bfs() {
	ans = 0;
	int m =n;
	vector<int> ids;
	ids.clear();
	if (m==2) {
		if (k==1) ans++;
		return;
	}
	for (int i = 1; i <= m; ++i) {
		if (deg[i] == 1) {
			ids.push_back(i);
		}
	}
	map<int, int> cnt;
	cnt.clear();
	for (int i = 0; i < ids.size(); ++i) {
		cnt[edges[ids[i]][0]]++;
	}
	queue<int> q;
	for (auto itr : cnt) {
		if (itr.second >= k) {
			q.push(itr.first);
		//	cout<<"u="<<itr.first<<endl;
		}
	}
	while(m > 2 && !q.empty()) {
		auto u = q.front();
		q.pop();
		if (cnt[u] < k) continue;
		if (cnt[u]%k!=0) {
			int x = cnt[u]/k;
			ans += x;
			cnt[u] %= k;
			deg[u] -= x*k;
			m -= x*k;
		} else {
			int x = cnt[u]/k;
			ans += x;
			cnt.erase(u);
			deg[u] -= x*k;
			m -= x*k;
			if (deg[u] > 1) continue;
			for (int i = 0; i < edges[u].size(); ++i) {
				int v = edges[u][i];
				if (deg[v] > 1) {
					cnt[v]++;
					if (cnt[v] >= k) {
						q.push(v);
					}
					break;
				}
			}
		}
	}
	if (m==2 && k==1) {
		ans++;
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>k;
		for (int i =1 ; i <= n; ++i) {
			deg[i] = 0;
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int x,y;
			scanf("%d%d",&x,&y);
			edges[x].push_back(y);
			edges[y].push_back(x);
			deg[x]++;
			deg[y]++;
		}
		bfs();
		cout<<ans<<endl;
	}
  return 0;
}
