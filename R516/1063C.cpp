#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 5002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int main() {
	string s;
	scanf("%d", &n);
	int y = 1;
	printf("%d %d\n", inf/2, y);
	fflush(stdout);
	int cl=0;
	int cr=0;
	cin>>s;
	if (s=="black") {
		cl = 1;
	}
	if (n==1) {
		printf("%d %d %d %d\n", inf/2+1, y, inf/2+1, y+1);
		return 0;
	}
	printf("%d %d\n", inf, y);
	fflush(stdout);
	cin>>s;
	if (s=="black") {
		cr = 1;
	}
	int l = inf/2;
	int r = inf;
	if (cl == cr) {
		l = 0;
		r = inf/2;
		cr=cl;
	}
	for (int i = 3; i <= n; ++i) {
		int mid=(l+r)/2;
		printf("%d %d\n", mid, y);
		fflush(stdout);
		cin>>s;
		int c=0;
		if (s=="black") {
			c=1;
		}
		if (c == cr) {
			r= mid;
		} else {
			l = mid;
			cl = c;
		}
	}
	printf("%d %d %d %d\n", l, y-1, r, y+1);
	return 0;
}
