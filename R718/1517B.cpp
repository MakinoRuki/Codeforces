#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 102
#define M 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t, n, m;
vector<int> b[N];
vector<int> v[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		vector<pair<int,pair<int,int>>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			b[i].clear();
			v[i].clear();
			for (int j = 1; j <= m; ++j) {
				int x;
				scanf("%d", &x);
				b[i].push_back(x);
				rk.push_back(make_pair(x, make_pair(i,j-1)));
			}
			for (int j = 0; j <= m; ++j) {
				v[i].push_back(0);
			}
		}
		sort(rk.begin(), rk.end());
		for (int i = 1; i <= m; ++i) {
			int id1 = rk[i-1].second.first;
			int id2 = rk[i-1].second.second;
			v[id1][id2] = i;
		}
		for (int i = 1; i <= n; ++i) {
			vector<int> res(m+1, 0);
			vector<int> tmp;
			tmp.clear();
			for (int j = 0; j < m; ++j) {
				if (v[i][j] > 0) {
					res[v[i][j]] = b[i][j];
				} else {
					tmp.push_back(b[i][j]);
				}
			}
			for (int j = 1; j <= m; ++j) {
				if (res[j] <= 0) {
					res[j] = tmp.back();
					tmp.pop_back();
				}
			}
			for (int j = 1; j <= m; ++j) {
				printf("%d", res[j]);
				if (j < m) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}

/*myturn.ca.gov*/
