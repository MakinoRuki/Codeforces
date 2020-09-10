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
#define N 10005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
bool vis[N];
int ans[N];
int main() {
	scanf("%d", &n);
	memset(vis, false, sizeof(vis));
	int id=1;
	for (int i=2; i <= n; ++i) {
		printf("? %d %d\n", id, i);
		fflush(stdout);
		int r1, r2;
		scanf("%d", &r1);
		printf("? %d %d\n", i, id);
		fflush(stdout);
		scanf("%d", &r2);
		if (r1<r2) {
			ans[i] = r2;
			vis[r2]=true;
		} else {
			ans[id]=r1;
			vis[r1]=true;
			id=i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			ans[id]=i;
			break;
		}
	}
	printf("!");
	for (int i = 1; i <= n; ++i) {
		printf(" %d", ans[i]);
	}
	printf("\n");
	return 0;
}
