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
#define N 200
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
ll x;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld", &x);
		int pw=1;
		while(x) {
			ll n=(1LL<<pw)-1;
			n=n*(n+1)/2;
			if (x < n) {
				break;
			}
			//cout<<x<<" "<<n<<endl;
			x -= n;
			pw++;
		}
		pw--;
		cout<<pw<<endl;
	}
	return 0;
}
