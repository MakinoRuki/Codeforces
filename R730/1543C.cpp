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
int t, n;
double dfs(double a, double b, double c, double v) {
	if (a < 0 && b < 0) {
		return 1.0;
	}
	double res = c;
	if (a < -eps) {
		if (b > v + eps) {
			res = res + (1.0 + dfs(a, b-v, c+v, v)) * b;
		} else {
			res = res + (1.0 + dfs(a, -1, c + b, v)) * b;
		}
	} else if (b < -eps) {
		if (a > v + eps) {
			res = res + (1.0 + dfs(a -v, b, c+v, v)) * a;
		} else {
			res = res + (1.0 + dfs(-1, b, c+a, v)) * a;
		}
	} else {
		if (a > v + eps) {
			res = res + (1.0 + dfs(a-v, b+v/2, c+v/2, v)) * a;
		} else {
			res = res + (1.0 + dfs(-1, b+a/2, c+a/2, v)) * a;
		}
		if (b > v + eps) {
			res = res + (1.0 + dfs(a+v/2, b-v, c + v/2, v)) * b;
		} else {
			res = res + (1.0 + dfs(a+b/2, -1, c+b/2, v)) * b;
		}
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		double a,b,c,v;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &v);
		printf("%.10lf\n", dfs(a, b, c, v));
	}
  return 0;
}
