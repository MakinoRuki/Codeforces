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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
int n, k;
int x[N], y[N];
int dl[N], dr[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n,&k);
		vector<int> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x[i]);
			rk.push_back(x[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &y[i]);
		}
		sort(rk.begin(), rk.end());
		int j = 1;
		int tot=0;
		for (int i = 1; i <= n; ++i) {
			tot++;
			while(j <= i && rk[i-1]-rk[j-1]>k) {
				tot--;
				j++;
			}
			dl[i]=tot;
			if (i>1)dl[i]=max(dl[i], dl[i-1]);
		}
	//	cout<<"x="<<dl[3]<<endl;
		j=n;
		tot=0;
		for (int i = n; i >= 1; --i) {
			tot++;
			while(j>=i && rk[j-1]-rk[i-1]>k) {
				tot--;
				j--;
			}
			dr[i]=tot;
			if (i<n)dr[i]=max(dr[i], dr[i+1]);
		}
	//	cout<<"y="<<dr[5]<<endl;
		int ans=0;
		for (int i = 1; i <= n; ++i) {
			if (i<n) {
				ans=max(ans, dl[i]+dr[i+1]);
			} else {
				ans=max(ans, dl[i]);
			}
		}
		for (int i = n; i>= 1; --i) {
			if (i > 1) {
				ans=max(ans, dr[i]+dl[i-1]);
			} else {
				ans=max(ans, dr[i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
