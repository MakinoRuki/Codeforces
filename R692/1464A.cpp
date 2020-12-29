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
#define M 31
#define N 100002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int xy[N];
bool vis[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		int tot=0;
		for (int i = 1; i <= n; ++i) {
			xy[i] = 0;
			vis[i] = false;
		}
		for (int i = 1; i <= m; ++i) {
			int x,y;
			scanf("%d%d", &x, &y);
			xy[x] = y;
			if (x!=y) tot++;
		}
		for (int i = 1; i <= n; ++i) {
			if (!vis[i] && xy[i]>0 && xy[i] != i) {
				int cur=xy[i];
				vis[i]=true;
				while(cur != i && !vis[cur] && cur != 0) {
					vis[cur]=true;
					cur=xy[cur];
				}
				if (cur == i) {
					tot++;
				}
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}
