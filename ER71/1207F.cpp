#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 500005
using namespace std;
int q;
int t, x, y;
int a[N];
int sum[720][720];
int main() {
	cin>>q;
	memset(a, 0, sizeof(a));
	memset(sum, 0, sizeof(sum));
	int sr = 710;
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d", &t, &x, &y);
		if (t==1) {
			a[x] += y;
			for (int i = 1; i <= 710; ++i) {
				sum[i][x%i] += y;
			}
		} else {
			if (x <= 710) {
				printf("%d\n", sum[x][y]);
			} else {
				int res = 0;
				for (int i = y; i <= 500000; i+=x) {
					res += a[i];
				}
				printf("%d\n", res);
			}
		}
	}
	return 0;
}
