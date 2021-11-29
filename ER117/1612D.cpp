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
#define M 1000005
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll a,b,x;
		scanf("%lld%lld%lld", &a, &b, &x);
		bool ok = false;
		while(true) {
			if (a == b) {
				if (x ==a) {
					ok=true;
				}
				break;
			}
			if (a == x || b == x) {
				ok=true;
				break;
			}
			if (a == 0 || b == 0) {
				break;
			}
			if (a < b) {
				swap(a,b);
			}
			if (((a%b) == (x%b)) && (x/b <= a/b)) {
				ok=true;
				break;
			}
			a %= b;
		}
		if (ok) puts("YES");
		else puts("NO");
	}
  return 0;
}

