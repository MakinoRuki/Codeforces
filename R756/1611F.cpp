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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
int s;
int t;
int n, k;
int a[N];
ll sum[N];
ll minv[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &s);
		sum[0] = 0;
	//	minv[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum[i] = sum[i-1];
			sum[i] += a[i];
		}
		int ans = 0;
		int lx = -1, rx = -1;
		int r = 1;
		for (int i = 1; i <= n; ++i) {
			while(r <= n && sum[r] - sum[i-1] + s >= 0) {
				r++;
			}
			if (r-i > ans) {
				ans = r-i;
				lx = i;
				rx = r-1;
			}
		}
		if (ans <= 0) puts("-1");
		else printf("%d %d\n", lx, rx);
	}
  return 0;
}

