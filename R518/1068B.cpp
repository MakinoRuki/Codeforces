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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll n, m, k, l;
ll b;
int main() {
	cin>>b;
	ll ans = 0LL;
	for (ll x = 1; x*x <= b; ++x) {
		if (b%x==0) {
			ans++;
			if (b/x != x) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
  return 0;
}
