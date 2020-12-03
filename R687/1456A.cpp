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
#define N 105
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,p,k;
string as;
int x,y;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &n,&p,&k);
		cin>>as;
		scanf("%d%d",&x,&y);
		ll ans = 2*inf;
		for (int i = 0; i < k; ++i) {
			vector<int> av;
			av.clear();
			for (int j = p+i; j <= n; j += k) {
				av.push_back(as[j-1]-'0');
			}
			if (av.empty()) continue;
			vector<int> sum;
			sum.resize(av.size());
			for (int j = sum.size()-1; j >= 0; --j) {
				if (j==sum.size()-1) {
					sum[j]=(av[j]?0:1);
				} else {
					sum[j]=sum[j+1];
					if (av[j]==0) sum[j]++;
				}
			}
			for (int j = 0; j < av.size(); ++j) {
				ll cur=((ll)j*(ll)k+(ll)i)*(ll)y+(ll)sum[j]*(ll)x;
				ans=min(ans, cur);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
