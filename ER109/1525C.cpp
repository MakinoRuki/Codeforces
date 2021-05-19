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
#include <time.h>
#define eps 1e-7
#define M 52
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int x[N];
int d[N];
int ans[N];
int calc(int id1, int id2) {
	//if (id1==7 && id2 == 5) cout<<"xx"<<" "<<x[id1]<<" "<<d[id1]<<" "<<x[id2]<<" "<<d[id2]<<endl;
	if (x[id1] > x[id2]) {
		swap(id1, id2);
	}
//	if (id1==5 && id2 == 7) cout<<"xx"<<" "<<x[id1]<<" "<<d[id1]<<" "<<x[id2]<<" "<<d[id2]<<endl;
	if (d[id1] == 1 && !d[id2]) {
		return (x[id2]-x[id1])/2;
	} else if (d[id1] && d[id2]) {
		return (m-x[id1]+m-x[id2])/2;
	} else if (!d[id1] && d[id2]) {
		return (m-x[id2]+x[id1]+m)/2;
	} else {
		return (x[id1]+x[id2])/2;
	}
	return -1;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x[i]);
			ans[i] = -1;
		}
		for (int i = 1; i <= n; ++i) {
			string ds;
			cin>>ds;
			if (ds == "L") d[i] = 0;
			else d[i] = 1;
		}
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			rk.push_back(make_pair(x[i], i));
		}
		sort(rk.begin(), rk.end());
		vector<int> v1, v2;
		v1.clear();
		v2.clear();
		for (int j = 1; j <= n; ++j) {
			int i = rk[j-1].second;
			if (x[i] % 2) {
				if (d[i] == 0) {
					if (!v1.empty() && d[v1.back()]) {
						ans[i] = calc(i, v1.back());
						ans[v1.back()] = ans[i];
						v1.pop_back();
					} else {
						v1.push_back(i);
					}
				} else {
					v1.push_back(i);
				}
			} else {
				if (d[i] == 0) {
					if (!v2.empty() && d[v2.back()]) {
						ans[i] = calc(i, v2.back());
						ans[v2.back()] = ans[i];
						v2.pop_back();
					} else {
						v2.push_back(i);
					}
				} else {
					v2.push_back(i);
				}
			}
		}
	//	cout<<"v1size="<<v1.size()<<endl;
		if (v1.size() >= 2) {
			while(v1.size() >= 2 && d[v1.back()] && d[v1[v1.size()-2]]) {
			//	cout<<v1.back()<<" "<<v1[v1.size()-2]<<endl;
			//	cout<<v1.back()<<" "<<v1[v1.size()-2]<<" "<<calc(v1.back(), v1[v1.size()-2])<<" "<<ans[v1.back()]<<endl;
				ans[v1.back()] = calc(v1.back(), v1[v1.size()-2]);
				ans[v1[v1.size()-2]] = ans[v1.back()];
				v1.pop_back();
				v1.pop_back();
			}
			reverse(v1.begin(), v1.end());
			while(v1.size() >= 2 && !d[v1.back()] && !d[v1[v1.size()-2]]) {
				ans[v1.back()] = calc(v1.back(), v1[v1.size()-2]);
				ans[v1[v1.size()-2]] = ans[v1.back()];
				v1.pop_back();
				v1.pop_back();
			}
			if (v1.size() == 2) {
		//		cout<<"v="<<v1[0]<<" "<<v1[1]<<endl;
			//	cout<<calc(v1[0], v1[1])<<endl;
				ans[v1[0]] = calc(v1[0], v1[1]);
			//	cout<<v1[0]<<" "<<calc(v1[0], v1[1])<<" "<<ans[v1[0]]<<endl;
				ans[v1[1]] = ans[v1[0]];
			}
		}
	//	cout<<"========="<<endl;
		if (v2.size() >= 2) {
			while(v2.size() >= 2 && d[v2.back()] && d[v2[v2.size()-2]]) {
				ans[v2.back()] = calc(v2.back(), v2[v2.size()-2]);
				ans[v2[v2.size()-2]] = ans[v2.back()];
				v2.pop_back();
				v2.pop_back();
			}
			reverse(v2.begin(), v2.end());
			while(v2.size() >= 2 && !d[v2.back()] && !d[v2[v2.size()-2]]) {
				ans[v2.back()] = calc(v2.back(), v2[v2.size()-2]);
				ans[v2[v2.size()-2]] = ans[v2.back()];
				v2.pop_back();
				v2.pop_back();
			}
			if (v2.size() == 2) {
				ans[v2[0]] = calc(v2[0], v2[1]);
				ans[v2[1]] = ans[v2[0]];
			}
		}
	//	cout<<"========="<<endl;
		for (int i = 1; i <= n; ++i) {
			printf("%d", ans[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
