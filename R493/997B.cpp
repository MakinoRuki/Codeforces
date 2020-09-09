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
#define N 1000005
#define eps 1e-6
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int cnt[50];
int main() {
	cin>>n;
	for (int i = 0; i < 49; ++i) {
		cnt[i] = inf+1;
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 49; ++j) {
			int r = (4*i+j*9)%49;
			cnt[r] = min(cnt[r], i+j);
		}
	}
	ll ans=0LL;
	for (int i = 0; i < 49; ++i) {
		if (cnt[i] <= n) {
			ans += (ll)(n-cnt[i]+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
