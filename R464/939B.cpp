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
#include <queue>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n;
int k;
ll a[N];
int main() {
	cin>>n>>k;
	ll ans=0LL;
	int id=0;
	for (int i = 1; i <= k; ++i) {
		scanf("%lld", &a[i]);
		if (n/a[i]*a[i]>ans || id==0) {
			ans = n/a[i]*a[i];
			id = i;
		}
	}
	cout<<id<<" "<<ans/a[id]<<endl;
	return 0;
}
