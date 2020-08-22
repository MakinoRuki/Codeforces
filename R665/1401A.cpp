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
int t, n, k;
int main() {
	cin>>t;
	for (int cas=1; cas<= t; ++cas) {
		scanf("%d%d", &n, &k);
		if (((n-k)%2==0) && (n-k)/2>=0 && (n-k)/2<=n) {
			cout<<0<<endl;
			continue;
		}
		if (((n+k)%2==0) && (n+k)/2>=0 && (n+k)/2<=n) {
			cout<<0<<endl;
		}
		if (n<=k) {
			cout<<abs(n-k)<<endl;
		} else {
			cout<<1<<endl;
		}
	}
	return 0;
}
