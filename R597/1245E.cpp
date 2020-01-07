#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 12
using namespace std;
typedef long long ll;
int mat[N][N];
double dp[N][N];
int n = 10;
double getres(int i, int j, int k) {
	if (i % 2) {
		if (j + k >= n) {
			i--;
			j = 2*n-j-k-1;
		} else {
			j += k;
		}
	} else {
		if (j - k < 0) {
			i--;
			j = k-j-1;
		} else {
			j -= k;
		}
	}
	if (i < 0 || j < 0) return -1;
	if (mat[i][j] > 0) {
		return min(dp[i][j], dp[i-mat[i][j]][j]);
	} else {
		return dp[i][j];
	}
}
int main() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin>>mat[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = 0.0;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i % 2) {
			for (int j = n-1; j >= 0; -- j) {
				if (i == 0 && j == 0) continue;
				double missing = 0;
				for (int k = 1; k <= 6; ++k) {
					double res=getres(i, j, k);
					if (res < 0) missing++;
					else dp[i][j] += res/6.0;
				}
				dp[i][j] += 1.0;
				dp[i][j] *= 6.0 / (6-missing);
			}
		} else {
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j == 0) continue;
				double missing = 0;
				for (int k = 1; k <= 6; ++k) {
					double res=getres(i, j, k);
					if (res < 0) missing++;
					else dp[i][j] += res/6.0;
				}
				dp[i][j] += 1.0;
				dp[i][j] *= 6.0 / (6-missing);
			}
		}
	}
	printf("%.7lf\n", dp[n-1][0]);
	return 0;
}
