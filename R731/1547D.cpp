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
int t;
string s;
int x[N];
int y[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x[i]);
		}
		for (int i = 1; i <= n; ++i) {
			y[i] = 0;
		}
		y[1] = 0;
		for (int b = 29; b >= 0; --b) {
			for (int i = 2; i <= n; ++i) {
				int xx = (((1<<b) & x[i-1])>0);
				int yy = (((1<<b) & y[i-1])>0);
			//	if (b == 2 && i == 4) cout<<xx<<" "<<yy<<endl;
				if (xx ^ yy) {
					if (!((1<<b)&x[i])) {
						y[i] |= (1<<b);
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", y[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
