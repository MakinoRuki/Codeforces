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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
vector<pair<int,int>> es;
int main() {
	cin>>n>>m;
	es.clear();
	for (int i = 2; i <= n; ++i) {
		es.push_back(make_pair(i, i-1));
	}
	if (es.size() > m) {
		puts("Impossible");
		return 0;
	}
	for (int i = 2; i <= n; ++i) {
		if (es.size() == m) break;
		vector<int> ps;
		ps.clear();
		int x=i;
		for (int j = 2; j*j <= x; ++j) {
			if (x%j==0) {
				ps.push_back(j);
				while(x%j==0) {
					x/=j;
				}
			}
		}
		if (x>1) ps.push_back(x);
		for (int j = i-2; j >= 1; --j) {
			if (es.size() == m) break;
			int j2;
			for (j2=0;j2<ps.size();++j2) {
				if (j%ps[j2]==0) {
					break;
				}
			}
			if (j2>=ps.size()) {
				es.push_back(make_pair(i, j));
			}
		}
	}
	if (es.size() < m) {
		puts("Impossible");
	} else {
		puts("Possible");
		for (int i = 0; i < es.size(); ++i) {
			printf("%d %d\n", es[i].first, es[i].second);
		}
	}
  return 0;
}
