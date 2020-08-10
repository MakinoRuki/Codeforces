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
#define N 2005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int main() {
	cin>>n;
	ll res = 1LL;
	for (int i = 1; i <= n; ++i) {
		res = res * (ll)i % mod;
	}
	ll res2 = 1LL;
	for (int i = 1; i < n; ++i) {
		res2 = res2 * 2LL % mod;
	}
	res = (res - res2 + mod) % mod;
	cout<<res<<endl;
	return 0;
}
