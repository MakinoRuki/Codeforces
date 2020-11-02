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
#define N 200002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		queue<pair<int,int>> q;
		int ans=0;
		q.push(make_pair(a[1],0));
		int i=2;
		while(!q.empty()) {
			auto cur=q.front();
			q.pop();
			int u=cur.first;
			int d=cur.second;
			ans=max(ans, d);
			while(i<=n) {
				q.push(make_pair(a[i], d+1));
				i++;
				if (i>n || a[i]<a[i-1]) {
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
