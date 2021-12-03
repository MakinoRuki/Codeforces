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
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
string s;
int t;
int n, q, m, k, e;
int a[N];
vector<int> ps[M];
void dfs(int p, ll x, int cur, int cnt, ll sum, ll& tot) {
	if (cur >= ps[p].size()) {
		if (cnt % 2) {
			tot -= x / sum;
		} else {
			tot += x / sum;
		}
		return ;
	}
	dfs(p, x, cur+1, cnt, sum, tot);
	dfs(p, x, cur+1, cnt+1, sum*ps[p][cur], tot);
}
ll getres(ll x, int p) {
	ll tot = 0;
	dfs(p, x, 0, 0, 1LL, tot);
	return tot;
}
int main() {
	for (int i =2; i <= 1000000; ++i) {
		int x=i;
		ps[i].clear();
		for (int j = 2; j * j <= x; ++j) {
			if (x%j == 0) {
				ps[i].push_back(j);
				while(x%j==0) {
					x/=j;
				}
			}
		}
		if (x>1) ps[i].push_back(x);
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int x,p,k;
		scanf("%d%d%d", &x, &p, &k);
		ll nx = getres(x, p);
		ll y1 = x+1, y2 = 10000000LL;
		while(y1 < y2) {
			ll mid = (y1+y2) /2;
			if (getres(mid, p) - nx >= k) {
				y2 = mid;
			} else {
				y1 = mid+1;
			}
		}
		printf("%lld\n", y2);
	}
  return 0;
}

