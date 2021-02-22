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
#define M 21
#define N 52
#define SZ 200000002
#define eps 1e-7
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int mat[N][N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &mat[i][j]);
		}
	}
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (mat[i][j] == 1) continue;
			bool found=false;
			for (int i2 = 1; i2 <= n; ++i2) {
				for (int j2 = 1; j2 <= n; ++j2) {
					if (i == i2 || j == j2) continue;
					if (mat[i2][j] + mat[i][j2] == mat[i][j]) {
						found=true;
						break;
					}
				}
			}
			if (!found) {
				ok=false;
				break;
			}
		}
	}
	if (!ok) {
		puts("No");
	} else {
		puts("Yes");
	}
  return 0;
}
