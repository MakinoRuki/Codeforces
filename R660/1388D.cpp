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
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n;
ll a[N];
int b[N];
vector<int> edges[N];
int deg[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i <= n; ++i) {
		if (b[i] > -1) {
			edges[i].push_back(b[i]);
			deg[b[i]]++;
		}
	}
	ll ans=0LL;
	vector<int> tmp;
	tmp.clear();
	queue<int> q;
	vector<int> res;
	res.clear();
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		ans += a[cur];
		if (a[cur] >= 0) {
			res.push_back(cur);
		} else {
			tmp.push_back(cur);
		}
		for (int i = 0; i < edges[cur].size(); ++i) {
			int v = edges[cur][i];
			deg[v]--;
			if (a[cur] >= 0) {
				a[v] += a[cur];
			}
			if (deg[v] == 0) {
				q.push(v);
			}
		}
	}
	for (int i = tmp.size()-1; i >= 0; --i) {
		res.push_back(tmp[i]);
	}
	cout<<ans<<endl;
	for (int i = 0; i < res.size(); ++i) {
		printf("%d", res[i]);
		if (i < res.size()-1) cout<<" ";
		else cout<<endl;
	}
  return 0;
}
