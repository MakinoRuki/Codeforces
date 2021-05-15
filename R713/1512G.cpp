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
#define M 52
#define N 10000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,c;
bool pm[N];
//vector<pair<int,int>> ps[N];
int sum[N];
int pm2[N];
int ans[N];
int main() {
	memset(pm, false, sizeof(pm));
	for (int i = 2; i*i < N; ++i) {
		if (!pm[i]) {
			pm2[i] = i;
			for (int j = i*i; j < N; j += i) {
				pm[j] = true;
				pm2[j] = i;
			}
		}
	}
	memset(sum, 0, sizeof(sum));
	memset(ans, -1, sizeof(ans));
//	cout<<"ok1"<<endl;
//	cout<<pm2[4]<<endl;
	int mv=0;
	// for (int i = 2; i < N; ++i) {
	// 	if (!pm[i]) {
	// 		ps[i].push_back(make_pair(i, 0));
	// 	} else {
	// 		int p = pm2[i];
	// 		mv=max(mv, (int)ps[i/p].size());
	// 		if (ps[i/p].empty() || ps[i/p][0].first != p) {
	// 			ps[i].push_back(make_pair(p, 0));
	// 		}
	// 		for (int j = 0; j < ps[i/p].size(); ++j) {
	// 			ps[i].push_back(ps[i/p][j]);
	// 		}
	// 	}
	// }
	// cout<<"mv="<<mv<<endl;
	// cout<<"ok2"<<endl;
	// vector<pair<ll,int>> rk;
	// rk.clear();
	// set<int> ss;
	// ss.clear();
//	int mv=0;
	for (int i = 1; i < N; ++i) {
		if (i == 1) {
			sum[1] = 1;
			ans[sum[1]] = 1;
		//	rk.push_back(make_pair(1, i));
			continue;
		}
		if (!pm[i]) pm2[i] = i;
		int p = pm2[i];
	//	if (p==0) cout<<"i="<<i<<" "<<p<<" "<<pm[i]<<endl;
		int sum2=0;
		int cur=1;
		sum2 += cur;
		int x = i;
		while(x%p == 0) {
			cur *= p;
			sum2 += cur;
			x/=p;
		}
		sum[i] = sum[x]*sum2;
		if (sum[i] <= 10000000) {
			if (ans[sum[i]] < 0) ans[sum[i]] = i;
		}
	// 	int tot=1;
	// 	int x = i;
	// //	if (i == 4) cout<<"pssize="<<ps[i].size()<<endl;
	// //	mv=max(mv, (int)ps[i].size());
	// //	int cc=0;
	// 	for (int j = 0; j < ps[i].size(); ++j) {
	// 		int p = ps[i][j].first;
	// 		int sum=0;
	// 		int cur = 1;
	// 		sum += cur;
	// 		while(x % p == 0) {
	// 		//	cc++;
	// 			cur *= p;
	// 			sum += cur;
	// 			x /= p;
	// 			ps[i][j].second++;
	// 		}
	// 		// if (i == 4) {
	// 		// 	cout<<"p="<<p<<" "<<sum<<endl;
	// 		// }
	// 		tot *= sum;
	// 	}

	//	rk.push_back(make_pair(sum[i], i));
	//	mv=max(mv, cc);
		//ss.insert(tot);
	}
//	cout<<"ok3"<<endl;
//	cout<<"msz="<<mv<<endl;
//	cout<<"sz="<<ss.size()<<endl;
	//sort(rk.begin(), rk.end());
	cin>>t;
	for (int cas=1;  cas<=t; ++cas) {
		scanf("%d", &c);
		printf("%d\n", ans[c]);
		// int l = 0, r = rk.size();
		// while(l < r) {
		// 	int mid= (l+r)/2;
		// 	if (rk[mid].first >= c) {
		// 		r = mid;
		// 	} else {
		// 		l = mid+1;
		// 	}
		// }
		// if (r == rk.size()) {
		// 	puts("-1");
		// } else {
		// 	if (rk[r].first == c) {
		// 		printf("%d\n", rk[r].second);
		// 	} else {
		// 		puts("-1");
		// 	}
		// }
	}
  return 0;
}
