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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 100
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
int a[N];
ll getds(int x, int y, int xx, int yy) {
	return (ll)abs(x-xx) + (ll)abs(y-yy);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		int x,y;
		scanf("%d%d", &x, &y);
		vector<vector<int>> ps = {{1,1}, {1,m}, {n,1}, {n,m}};
		ll ans = -1;
		int id1 = -1;
		int id2 = -1;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ll det = 0LL;
				det += getds(x, y, ps[i][0], ps[i][1]);
				det += getds(ps[i][0], ps[i][1], ps[j][0], ps[j][1]);
				det += getds(ps[j][0], ps[j][1], x, y);
				if (det > ans) {
					ans = det;
					id1 = i;
					id2 = j;
				}
			}
		}
		printf("%d %d %d %d\n", ps[id1][0], ps[id1][1], ps[id2][0], ps[id2][1]);
	}
  return 0;
}
