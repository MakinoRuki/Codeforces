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
#define eps 1e-7
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, p;
int a,b,c;
int getds(ll x) {
	int cnt=0;
	while(x) {
		cnt++;
		x/=10;
	}
	return cnt;
}
ll getgcd(ll x, ll y) {
	return y==0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &a, &b, &c);
		ll g = 1;
		for (int i = 2; i <= c; ++i) {
			g *= 10;
		}
		ll x = g, y = g;
		while(getds(x) < a) {
			x *= 2;
		}
		while(getds(y) < b) {
			y *= 3;
		}
	//	cout<<"g="<<getgcd(x, y)<<endl;
		printf("%lld %lld\n", x, y);
	}
  return 0;
}
