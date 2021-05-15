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
#define M 2002
#define N 102
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
bool dp[N][N*M];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	while(true) {
		int id = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] % 2) {
				id = i;
				break;
			}
		}
		if (id <= 0) {
			for (int i = 1; i<= n; ++i) {
				a[i] /= 2;
			}
		} else {
			break;
		}
	}
	int sum=0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
	}
	if (sum % 2) {
		puts("0");
	} else {
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n*2000; ++j) {
				dp[i][j] = false;
			}
		}
		dp[0][0] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= n*2000; ++j) {
				if (dp[i][j]) {
					dp[i+1][j] = true;
					dp[i+1][j+a[i+1]] = true;
				}
			}
		}
		if (dp[n][sum/2]) {
			int id = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] % 2) {
					id = i;
					break;
				}
			}
			puts("1");
			printf("%d\n", id);
		} else {
			puts("0");
		}
	}
	return 0;
}
