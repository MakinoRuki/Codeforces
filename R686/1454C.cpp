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
int t,n;
int a[N];
int pos[N];
int ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			pos[i]=0;
			ans[i]=0;
		}
		for (int i = 1; i <= n; ++i) {
			if (i-pos[a[i]] > 1) {
				ans[a[i]]++;
			}
			pos[a[i]] = i;
		}
		int res=n+1;
		for (int i = 1; i <= n; ++i) {
			if (pos[i]>0) {
			//	cout<<"i="<<i<<endl;
				if (n+1-pos[i]>1) {
					ans[i]++;
				}
				res=min(res, ans[i]);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
