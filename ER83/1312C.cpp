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
#define N 50
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int t, n, k;
ll a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>k;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		bool ok = true;
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			ll x = a[i];
			int pw = 0;
			while(x) {
				int r = x%k;
				if (r > 1) {
					ok = false;
					break;
				}
				if (r == 1) {
					if (ss.find(pw) != ss.end()) {
						ok = false;
						break;
					}
					ss.insert(pw);
				}
				pw++;
				x /= k;
			}
			if (!ok) break;
		}
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
