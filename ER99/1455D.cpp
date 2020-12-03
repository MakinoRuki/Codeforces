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
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, x;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int i;
		for (i = 2; i <= n; ++i) {
			if (a[i] < a[i-1]) {
				break;
			}
		}
		if (i > n) {
			cout<<0<<endl;
		} else {
			int ans=inf;
			for (int i = 1; i <= n; ++i) {
				int c[N];
				int b[N];
				int x2=x;
				for (int j = 1; j <= n; ++j) {
					if (i != j) b[j]=a[j];
					else b[j]=x2;
					c[j]=a[j];
				}
				sort(b+1, b+n+1);
				int cnt=0;
				while(true) {
					bool found=false;
					int j;
					int minv=inf;
					int id=-1;
					for (j = 1; j <= n; ++j) {
						if (c[j] > b[j] && c[j] > x2) {
							if (c[j]<minv) {
								minv=c[j];
								id=j;
							}
						}
					}
					if (id >= 1) {
						swap(c[id], x2);
						cnt++;
					} else {
						break;
					}
				}
				int j;
				for (j = 1; j <= n; ++j) {
					if (b[j] != c[j]) {
						break;
					}
				}
				if (j>n) {
					ans=min(ans, cnt);
				}
			}
			if (ans>=inf) cout<<-1<<endl;
			else printf("%d\n", ans);
		}
	}
	return 0;
}
