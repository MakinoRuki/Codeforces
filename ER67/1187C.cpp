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
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[N];
vector<pair<int,int>> sgs[2];
int main() {
	cin>>n>>m;
	for (int i = 0; i < m; ++i) {
		int t,l,r;
		scanf("%d%d%d", &t, &l, &r);
		sgs[t].push_back(make_pair(l,r));
	}
	bool ok=true;
	for (int i = 1; i <= n; ++i) {
		a[i]=1000000000;
	}
	for (int i = 2; i <= n; ++i) {
		int j=0;
		for (j = 0; j < sgs[1].size(); ++j) {
			if (i>sgs[1][j].first && i<=sgs[1][j].second) {
				break;
			}
		}
		if (j >= sgs[1].size()) {
			a[i]=a[i-1]-1;
		}
	}
	for (int i = 0; i < sgs[0].size(); ++i) {
		int j;
		for (j = sgs[0][i].first+1; j <= sgs[0][i].second; ++j) {
			if (a[j]<a[j-1]) {
				break;
			}
		}
		if (j > sgs[0][i].second) {
			ok=false;
			break;
		}
	}
	if (!ok) {
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
		for (int i = 1; i <= n; ++i) {
			printf("%d", a[i]);
			if (i<n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
