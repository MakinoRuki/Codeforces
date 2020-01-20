#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,m;
int x[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		cin>>x[i];
	}
	vector<pair<int, int>> rk;
	rk.clear();
	set<pair<int, int>> cnt;
	cnt.clear();
	for (int i = 1; i < m; ++i) {
		int a = x[i];
		int b = x[i+1];
		if (a > b) swap(a, b);
		if (a != b) {
			rk.push_back(make_pair(a, b));
		}
	}
	sort(rk.begin(), rk.end());
	vector<ll> ans(n+1, 0);
	for (int i = 1; i < m; ++i) {
		ans[1] += abs(x[i]-x[i+1]);
	}
	int j = 0;
	while(j < rk.size() && rk[j].first == 1) {
		cnt.insert(make_pair(rk[j].second, j));
		j++;
	}
	for (int i = 2; i <= n; ++i) {
		ll num=0;
		ll sum=0;
		int k = j;
		while(k < rk.size() && rk[k].first == i) {
			k++;
		}
		while(!cnt.empty() && (*(cnt.begin())).first < i) {
			cnt.erase(*cnt.begin());
		}
		while(!cnt.empty() && (*(cnt.begin())).first == i) {
			num++;
			sum += rk[(*(cnt.begin())).second].first;
			cnt.erase(*cnt.begin());
		}
		ll num2 = k-j;
		ll num3 = cnt.size();
		ans[i] = ans[1];
		ans[i] += 2LL * sum - i * num;
		ans[i] += (i-1) * num2;
		ans[i] -= num3;
		while(j < k) {
			cnt.insert(make_pair(rk[j].second, j));
			j++;
		}
	}
	for (int i = 1; i <=n ; ++i) {
		cout<<ans[i];
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
