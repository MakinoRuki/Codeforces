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
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		map<int, int> cnt;
		cnt.clear();
		cnt[0] = 1;
		int sum = 0;
		ll ans = 0LL;
		for (int i =1; i <= n; ++i) {
			sum += s[i-1]-'0';
		//	cout<<i<<" "<<sum<<endl;
			ans += (ll)cnt[sum-i];
			cnt[sum-i]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
