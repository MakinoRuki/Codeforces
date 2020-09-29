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
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
int det[N];
int pre[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			pre[i]=0;
			det[i] = -1;
		}
		for (int i = 1; i <= n; ++i) {
			int tmp=i-pre[a[i]];
			det[a[i]] = max(det[a[i]], tmp);
			pre[a[i]] = i;
		}
		for (int i = 1; i <= n; ++i) {
			if (pre[i]<0) continue;
			int tmp=n+1-pre[i];
			det[i] = max(det[i], tmp);
		}
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			if (det[i]>=0) {
			//	cout<<"i="<<i<<" "<<det[i]<<endl;
				rk.push_back(make_pair(det[i], i));
			}
		}
		sort(rk.begin(), rk.end());
		set<int> ss;
		ss.clear();
		int j = 0;
		for (int i = 1; i <= n; ++i) {
			while(j < rk.size() && rk[j].first<=i) {
				ss.insert(rk[j].second);
				j++;
			}
			if (!ss.empty()) {
				auto res=*ss.begin();
				printf("%d", res);
			} else {
				printf("-1");
			}
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
