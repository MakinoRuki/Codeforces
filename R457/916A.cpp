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
#define M 20005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int x;
int h,m;
bool check(int t) {
	int h2=t/60;
	int m2=t%60;
	if ((h2%10==7) || (h2/10==7) || (m2%10==7) || (m2/10==7)) {
		return true;
	}
	return false;
}
int main() {
	cin>>x>>h>>m;
	int ans=inf;
	for (int det=0; det<1440; ++det) {
		int t1=(h*60+m-det+1440)%1440;
		if (det%x) continue;
		if (check(t1)) {
			ans = min(ans, det/x);
		}
	}
	cout<<ans<<endl;
	return 0;
}
