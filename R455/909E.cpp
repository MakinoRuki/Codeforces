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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m;
int e[N];
vector<int> edges[N];
bool vis[N];
int deg[N];
int main() {
	cin>>n>>m;
	memset(deg,0,sizeof(deg));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &e[i]);
		edges[i].clear();
	}
	for (int i =1 ; i <= m; ++i) {
		int t1,t2;
		scanf("%d%d", &t1,&t2);
		edges[t2].push_back(t1);
		deg[t1]++;
	}
	queue<int> q[2];
	for (int i = 0; i < n; ++i) {
		if (deg[i]==0) {
			q[e[i]].push(i);
		}
	}
	int ans=0;
	int cnt=0;
	while(cnt<n) {
		while(!q[0].empty()) {
			auto cur=q[0].front();
			q[0].pop();
			cnt++;
		//	cout<<"cur0="<<cur<<endl;
			for (int i = 0; i < edges[cur].size(); ++i) {
				int v=edges[cur][i];
				deg[v]--;
				if (deg[v]==0) {
					q[e[v]].push(v);
				}
			}
		}
		if (!q[1].empty()) {
			ans++;
			while(!q[1].empty()) {
				auto cur=q[1].front();
				q[1].pop();
				cnt++;
			//	cout<<"cur1="<<cur<<endl;
				for (int i = 0; i < edges[cur].size(); ++i) {
					int v=edges[cur][i];
					deg[v]--;
					if (deg[v]==0) {
						q[e[v]].push(v);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
