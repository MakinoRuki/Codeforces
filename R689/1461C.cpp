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
int t;
int n, m;
int a[N];
vector<pair<int, double>> exv;
int BIT[N];
int lowbit(int x) {
	return x&(-x);
}
void update(int pos) {
	while(pos <= n) {
		BIT[pos]++;
		pos += lowbit(pos);
	}
}
int query(int pos) {
	int res=0;
	while(pos>0) {
		res += BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		exv.clear();
		for (int i = 0; i < m; ++i) {
			int r;
			double p;
			scanf("%d%lf", &r, &p);
			exv.push_back(make_pair(r, p));
		}
		for (int i = 1; i <= n; ++i) {
			BIT[i] = 0;
		}
		int id = -1;
		for (int i = 1; i <= n; ++i) {
			if (query(n)-query(a[i]) > 0) {
				id = i;
			}
			update(a[i]);
		}
		if (id < 0) printf("%.10lf\n", 1.0);
		else {
			double res=1.0;
			for (int j = 0; j < exv.size(); ++j) {
				if (exv[j].first >= id) res *= (1.0 - exv[j].second);
			}
			res = 1.0 - res;
			printf("%.10lf\n", res);
		}
	}
	return 0;
}
