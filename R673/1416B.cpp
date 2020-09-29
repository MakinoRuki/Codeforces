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
#define N 20000
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
ll sum[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sum[0]=0;
		for (int i = 1; i <= n; ++i) {
			sum[i]=sum[i-1]+a[i];
		}
		if (sum[n]%n!=0) {
			cout<<-1<<endl;
		} else {
			ll x=sum[n]/n;
			vector<pair<pair<int,int>,ll>> ans;
			ans.clear();
			for (int i = 2; i <= n; ++i) {
				if (a[i]%i==0) {
					ans.push_back(make_pair(make_pair(i,1),a[i]/i));
					a[1] += a[i];
					a[i]=0;
				} else {
					int r=a[i]%i;
					r=i-r;
					ans.push_back(make_pair(make_pair(1,i),r));
					a[1] -= r;
					a[i] += r;
					ans.push_back(make_pair(make_pair(i,1),a[i]/i));
					a[1] += a[i];
					a[i] = 0;
				}
			}
			for (int i = 2; i <= n; ++i) {
				ans.push_back(make_pair(make_pair(1, i), x));
				a[1] -= x;
				a[i] += x;
			}
			int sz=(int)ans.size();
			printf("%d\n", sz);
			for (int i = 0; i < sz; ++i) {
				printf("%d %d %lld\n", ans[i].first.first, ans[i].first.second, ans[i].second);
			}
		}
	}
	return 0;
}
