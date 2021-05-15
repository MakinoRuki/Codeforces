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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, q;
int a[N];
int id[100];
int main() {
	scanf("%d%d", &n, &q);
	memset(id, -1, sizeof(id));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (id[a[i]] < 0) {
			id[a[i]] = i;
		}
	}
	for (int i = 1; i <= q; ++i) {
		int tq;
		scanf("%d", &tq);
		printf("%d", id[tq]);
		if (i < q) cout<<" ";
		else cout<<endl;
		for (int j = 1; j <= 50; ++j) {
			if (id[j] >= 1 && id[j] < id[tq]) {
				id[j]++;
			}
		}
		id[tq] = 1;
	}
  return 0;
}
