#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 3005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m, a, b;
ll h[N][N];
ll g0, x, y, z;
ll minv[N][N];
int main() {
	cin>>n>>m>>a>>b;
	cin>>g0>>x>>y>>z;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i==0 && j == 0) h[i][j] = g0;
			else {
				h[i][j] = (g0*x+y)%z;
				g0 = h[i][j];
			}
		}
	}
	for (int j = 0; j < m; ++j) {
		deque<int> q;
		for (int i = 0; i < n; ++i) {
			while(!q.empty() && h[i][j] < h[q.back()][j]) {
				q.pop_back();
			}
			q.push_back(i);
			while(!q.empty() && q.front() <= i-a) {
				q.pop_front();
			}
			if (i >= a-1) {
				minv[j][i] = h[q.front()][j];
			}
		}
	}
	ll ans = 0LL;
	for (int i = 0; i + a<=n; ++i) {
		deque<pair<ll, int> > q;
		for (int j = 0; j < m; ++j) {
			while(!q.empty() && minv[j][i+a-1] <= q.back().first) {
				q.pop_back();
			}
			q.push_back(make_pair(minv[j][i+a-1], j));
			while(!q.empty() && q.front().second <= j-b) {
				q.pop_front();
			}
			if (j >= b-1) {
				ans = (ans + q.front().first);
			}
		}	
	}
	cout<<ans<<endl;
	return 0;
}
