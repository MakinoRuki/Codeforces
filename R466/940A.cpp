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
#define M 20005
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,d;
int x[N];
int main() {
	cin>>n>>d;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
	}
	sort(x+1, x+n+1);
	int i = 1;
	int ans=n;
	int j = 1;
	while(i<=n) {
		while(j <= n && x[j]-x[i]<=d) {
			j++;
		}
		ans = min(ans, n-(j-i));
		int i2=i;
		while(i2<=n && x[i2] == x[i]) {
			i2++;
		}
		i = i2;
	}
	cout<<ans<<endl;
	return 0;
}
