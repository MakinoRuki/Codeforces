#pragma GCC optimize(2)
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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		if (n == 1) {
			if (a[1] == 0) {
				printf("1 2\n");
			} else {
				printf("2 1\n");
			}
			continue;
		}
		int id = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] == 0 && a[i+1] == 1) {
				id = i;
				break;
			}
		}
		if (id == 0 && a[n] != 0 && a[1] != 1) {
			puts("-1");
		} else {
			if (id != 0) {
				for (int i = 1; i <= id; ++i) {
					printf("%d ", i);
				}
				printf("%d", n+1);
				for (int i = id+1; i <= n; ++i) {
					printf(" %d", i);
				}
				cout<<endl;
			} else if (a[n] == 0) {
				for (int i =1 ; i <= n; ++i) {
					printf("%d ", i);
				}
				printf("%d\n", n+1);
			} else if (a[1] == 1) {
				printf("%d", n+1);
				for (int i = 1; i <= n; ++i) {
					printf(" %d", i);
				}
				cout<<endl;
			}
		}
	}
  return 0;
}
