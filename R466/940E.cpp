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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, c;
int a[N];
ll dp[N];
int main() {
	cin>>n>>c;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	dp[0] = 0;
	multiset<int> ss;
	ss.clear();
	ll sum=0LL;
	for (int i = 1; i <= n; ++i) {
		dp[i]=dp[i-1]+a[i];
		sum += a[i];
		ss.insert(a[i]);
		if (i-c>=1) {
			sum -= a[i-c];
			ss.erase(ss.find(a[i-c]));
		}
		if (i>=c) {
			auto num=*ss.begin();
			dp[i]=min(dp[i],dp[i-c]+sum-num);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
