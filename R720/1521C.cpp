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
#define N 10005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int ans[N];
int main() {
	cin>>t;
	while(t-->0) {
		scanf("%d", &n);
		int i = 1;
		int x;
		int id = 0;
		while(i <= n) {
			if (i<n) {
				printf("? 2 %d %d %d\n", i, i+1, 1);
				fflush(stdout);
				scanf("%d", &x);
				if (x == 1) {
					id = i;
					break;
				} else if (x == 2) {
					printf("? 2 %d %d %d\n", i+1, i, 1);
					fflush(stdout);
					scanf("%d", &x);
					if (x==1) {
						id = i+1;
						break;
					}
				}
				i += 2;
			} else {
				id = i;
				break;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i == id) ans[i] = 1;
			else {
				printf("? 1 %d %d %d\n", id, i, n-1);
				fflush(stdout);
				scanf("%d", &ans[i]);
			}
		}
		printf("!");
		for (int i = 1; i <= n; ++i) {
			printf(" %d", ans[i]);
		}
		cout<<endl;
	}
  return 0;
}
