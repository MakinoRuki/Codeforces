#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 400005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n, m;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m;
		ll b = (n-m)/(m+1);
		ll r = (n-m)%(m+1);
		ll res = (b+1)*(b+2)/2*r + b*(b+1)/2*(m+1-r);
		res = (ll)n*(ll)(n+1)/2 - res;
		cout<<res<<endl;
	}
	return 0;
}
