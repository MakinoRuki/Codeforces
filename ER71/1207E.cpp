#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
int t, b;
int res[N];
int main() {
	printf("?");
	for (int i = 1; i <= 100; ++i) {
		printf(" %d", i);
	}
	printf("\n");
	fflush(stdout);
	int x, y;
	scanf("%d", &x);
	printf("?");
	for (int i = 1; i <= 100; ++i) {
		printf(" %d", i<<7);
	}
	printf("\n");
	fflush(stdout);
	scanf("%d", &y);
	x >>= 7;
	int res = (x<<7) + (y%128);
	printf("! %d\n", res);
    return 0;
}
