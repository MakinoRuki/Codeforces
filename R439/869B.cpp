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
#define M 20005
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,k;
ll a,b;
int main() {
	cin>>a>>b;
	if (b-a>=10) {
		cout<<0<<endl;
	} else {
		ll r=1;
		for (ll i=a+1; i<=b; ++i) {
			r=r*(i%10)%10;
		}
		cout<<r<<endl;
	}
	return 0;
}
