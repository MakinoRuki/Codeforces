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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int deg[N];
int n;
double s;
int main() {
	memset(deg, 0, sizeof(deg));
	cin>>n>>s;
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
	}
	int cnt=0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) cnt++;
	}
	double ans = 2.0 * s / (double)cnt;
	printf("%.8lf\n", ans);
	return 0;
}
