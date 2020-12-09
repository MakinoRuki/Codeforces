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
#define M 20005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,q;
int n;
int main() {
	int a=-1, b=-1;
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		string s;
		cin>>s;
		if (s == "+") {
			int x,y;
			scanf("%d%d", &x, &y);
			if (x > y) swap(x, y);
			a = max(a, x);
			b = max(b, y);
		} else {
			int h,w;
			scanf("%d%d", &h, &w);
			if (h > w) swap(h, w);
			if (h >= a && w >= b) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
	return 0;
}
