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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t, n;
int a[N];
bool dv[N];
int main() {
	cin>>t;
	for (int cas=1; cas<= t; ++cas) {
		scanf("%d", &n);
		int minv;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (i==1) minv=a[i];
			else minv=min(minv, a[i]);
			dv[i] = false;
		}
		vector<int> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			if (a[i]%minv==0) {
				dv[i] = true;
				rk.push_back(a[i]);
			}
		}
		sort(rk.begin(), rk.end());
		int j = 0;
		for (int i = 1; i <= n; ++i) {
			if (dv[i]) {
				a[i] = rk[j];
				j++;
			}
		}
		int i=1;
		for (i = 1; i <= n; ++i) {
			if (a[i]<a[i-1]) break;
		}
		if (i>n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
