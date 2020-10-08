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
#include <queue>
#include <cmath>
#define N 5002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m;
int a[N], b[N];
int main() {
	cin>>n>>m;
	int id=0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d",&a[i],&b[i]);
		if (i==1) {
			id=1;
		} else {
			if (a[i]*m*b[id]<b[i]*m*a[id]) {
				id=i;
			}
		}
	}
	double res=(double)a[id]*(double)m/(double)b[id];
	printf("%.10lf\n", res);
	return 0;
}
