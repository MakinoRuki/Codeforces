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
#define N 200
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
int p[N];
int main() {
	cin>>t;
	for (int cas=1; cas <=t ;++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
			if (p[i]==0) {
				rk.push_back(make_pair(a[i], i));
			}
		}
		sort(rk.begin(), rk.end());
		reverse(rk.begin(), rk.end());
		int j = 0;
		for (int i = 1; i <= n; ++i) {
			if (p[i]==0) {
				a[i] = rk[j].first;
				j++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d",a[i]);
			if (i<n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
