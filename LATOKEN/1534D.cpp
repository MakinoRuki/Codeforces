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
#define M 10005
#define N 2010
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int d[N];
void query(vector<int>& ns, set<pair<int,int>>& ss) {
	for (int i = 0; i < ns.size(); ++i) {
		if (ns[i] != 1) {
			printf("? %d\n", ns[i]);
			fflush(stdout);
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &d[j]);
				if (d[j] == 1) ss.insert(make_pair(min(ns[i], j), max(ns[i], j)));
			}
		}
	}
}
int main() {
	cin>>n;
	printf("? %d\n", 1);
	fflush(stdout);
	vector<int> ns[2];
	set<pair<int,int>> ss;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
		ns[d[i]%2].push_back(i);
		if (d[i] == 1) ss.insert(make_pair(1, i));
	}
	
	if (ns[0].size() <= ns[1].size()) {
		query(ns[0], ss);
	} else {
		query(ns[1], ss);
	}
	puts("!");
	for (auto pr : ss) {
		printf("%d %d\n", pr.first, pr.second);
	}
  return 0;
}
