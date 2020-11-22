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
int n, k;
int t;
int x,y;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &x, &y);
		x=abs(x);
		y=abs(y);
		if (x<y) swap(x, y);
		int det=x-y;
		int res=2*y;
		if (det>0) {
			det--;
			res++;
			res += 2*det;
		}
		printf("%d\n", res);
	}
	return 0;
}
