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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, p;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		int c1=0,c2=0;
		for (int i= 1 ; i <= n; ++i) {
			int r;
			scanf("%d", &r);
			if (r == 1 || r == 3) {
				c1++;
			} else {
				c2++;
			}
		}
		printf("%d\n", c1);
	}
  return 0;
}
