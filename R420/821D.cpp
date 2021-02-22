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
#define M 21
#define N 10005
#define SZ 200000002
#define eps 1e-7
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
vector<pair<int,int>> pts;
int dis[N];
void solve(int s, int t) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, s));
	while(!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		int d = top.first;
		int u = top.second;
		int xa=pts[u-1].first;
		int ya=pts[u-1].second;
		if (dis[u] < d) continue;
	//	cout<<"u="<<u<<" "<<dis[u]<<endl;
		for (int i = 1; i <= k; ++i) {
			if (i == u) continue;
			int xb=pts[i-1].first;
			int yb=pts[i-1].second;
			int dx=abs(xa-xb);
			int dy=abs(ya-yb);
			if (dx+dy==1) {
				if (dis[i] > dis[u]) {
					dis[i] = dis[u];
					pq.push(make_pair(dis[i], i));
				}
			} else if (dx<=2 || dy<=2) {
				if (dis[i] > dis[u] + 1) {
					dis[i] = dis[u]+1;
					pq.push(make_pair(dis[i], i));
				}
			}
		}
		if (t > k) {
			int xb=n;
			int yb=m;
			int dx=abs(xa-xb);
			int dy=abs(ya-yb);
			if (dx+dy==1 || xa==xb || ya==yb) {
				if (dis[t] > dis[u]+1) {
					dis[t] = dis[u]+1;
				}
			} else if (dx<=1 || dy<=1) {
				if (dis[t] > dis[u] + 1) {
					dis[t] = dis[u] + 1;
				}
			}
		}
	//	cout<<t<<" "<<dis[t]<<endl;
	}
}
int main() {
	cin>>n>>m>>k;
	pts.clear();
	int id=0;
	int id2=0;
	for (int i = 1; i <= k; ++i) {
		int r, c;
		scanf("%d%d", &r, &c);
		pts.push_back(make_pair(r, c));
		if (r == 1 && c== 1) {
			id = i;
		}
		if (r==n && c==m) {
			id2=i;
		}
	}
	if (id2<=0) id2 = k+1;
	for (int i = 1; i <= k+1; ++i) {
		dis[i] = inf;
	}
	dis[id] = 0;
	solve(id, id2);
	if (dis[id2] >= inf) cout<<-1<<endl;
	else cout<<dis[id2]<<endl;
  return 0;
}
