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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
int b[N];
int cnt[N][2];
bool check(int x, int l, int r) {
//	cout<<x<<" "<<l<<" "<<r<<endl;
	int o1 = cnt[x][1];
	int e1 = cnt[x][0];
	int o2=0,e2=0;
	int len=(r-l+1);
	if (l%2==0 && r %2 ==0) {
		o2=len/2;
		e2=len-o2;
	} else {
		e2=len/2;
		o2=len-e2;
	}
	return (o1==o2 && e1==e2);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			b[i] = a[i];
			if (i%2) cnt[a[i]][1]++;
			else cnt[a[i]][0]++;
		}
		sort(b+1, b+n+1);
		bool ok = true;
		int st = 1;
		for (int i = 1; i <= n; ++i) {
			if (i > 1 && b[i] != b[i-1]) {
				if (!check(b[i-1], st, i-1)) {
					ok=false;
					break;
				}
				st = i;
			}
		}
		if (!check(b[n], st, n)) {
			ok= false;
		}
		if (!ok) puts("NO");
		else puts("YES");
		for (int i = 1; i <= n; ++i) {
			cnt[a[i]][0] = 0;
			cnt[a[i]][1] = 0;
		}
	}
  return 0;
}
