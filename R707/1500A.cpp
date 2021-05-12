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
#define M 25
#define N 2500010
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
vector<int> cnt[N];
int prs[N*2][2];
int main() {
	cin>>n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]].push_back(i);
	}
	for (int i = 1; i <  N; ++i) {
		if (cnt[i].size() >= 4) {
			puts("YES");
			printf("%d %d %d %d\n", cnt[i][0], cnt[i][1], cnt[i][2], cnt[i][3]);
			return 0;
		}
	}
	vector<int> ids;
	ids.clear();
	for (int i = 1; i < N; ++i) {
		if (ids.size() >= 4) break;
		if (cnt[i].size() >= 2) {
			ids.push_back(cnt[i][0]);
			ids.push_back(cnt[i][1]);
		}
	}
	if (ids.size() >= 4) {
		puts("YES");
		printf("%d %d %d %d\n", ids[0], ids[2], ids[1], ids[3]);
		return 0;
	}
	memset(prs, -1, sizeof(prs));
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int sum = a[i]+a[j];
			if (prs[sum][0] >= 1) {
				if (prs[sum][0] != i && prs[sum][1] != i && prs[sum][0] != j && prs[sum][1] != j) {
					puts("YES");
					printf("%d %d %d %d\n", prs[sum][0], prs[sum][1], i, j);
					return 0;
				}
			} else {
				prs[sum][0] = i;
				prs[sum][1] = j;
			}
		}
	}
	puts("NO");
  return 0;
}
