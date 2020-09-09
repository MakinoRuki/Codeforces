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
#define N 300
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	a[0] = 0;
	a[n+1] = 1001;
	int ans=0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			if (a[j]-a[i]-1==j-i-1) {
				ans=max(ans, j-i-1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
